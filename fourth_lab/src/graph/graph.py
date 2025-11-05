"""Файл graph.py необходим для представления самого контейнера"""

from typing import Generic, TypeVar, List, Set, Tuple, Hashable, Dict, Union
import copy
from src.graph.settings import POSITIVE_EDGE, NEGATIVE_EDGE, DEFAULT_EDGE
from src.graph.vertex import Vertex
from src.graph.edge import Edge
from src.graph.exceptions.exceptions import IncorrectVertex, IncorrectEdge, IncorrectPosition
from src.graph.iterators.bidirectional_adjacent_vertices_iterator import BidirectionalAdjacentVerticesIterator
from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIncidentEdgesIterator
from src.graph.iterators.bidirectional_vertex_and_edge_iterator import BidirectionalVertexAndEdgeIterator
from src.graph.iterators.const_bidirectional_adjacent_vertices_iterator import \
    ConstBidirectionalAdjacentVerticesIterator
from src.graph.iterators.const_bidirectional_incidence_edges_iterator import ConstBidirectionalIncidentEdgesIterator
from src.graph.iterators.const_bidirectional_vertex_and_edge_iterator import ConstBidirectionalVertexAndEdgeIterator
from src.graph.utils import Counter
import logging


T = TypeVar('T', bound=Hashable)


class Graph(Generic[T]):
    """
    Контейнер для хранения и управления графом с матрицей инцидентности.

    Граф представлен с помощью матрицы инцидентности (специальная матрица,
    в которой строки — вершины, столбцы — рёбра). Также хранятся словари
    вершин и рёбер для быстрого доступа по id. Класс поддерживает типизацию (Generic[T])
    и предоставляет двусторонние итераторы для обхода элементов.

    Матрица инцидентности содержит значения:
        - 1 (POSITIVE_EDGE): вершина является началом ребра.
        - -1 (NEGATIVE_EDGE): вершина является концом ребра.
        - 0 (DEFAULT_EDGE): вершина не связана с ребром.

    Attributes:
        _vertices (Dict[int, Vertex[T]]): Словарь вершин, ключ — id вершины, значение — объект Vertex.
        _edges (Dict[int, Edge]): Словарь рёбер, ключ — id ребра, значение — объект Edge.
        _incidence_matrix (List[List[int]]): Матрица инцидентности.
        _vertex_order (List[int]): Упорядоченный список id вершин (порядок строк в матрице).
        _edge_order (List[int]): Упорядоченный список id рёбер (порядок столбцов в матрице).
        _next_vertex_id (int): Счётчик для автоматического назначения id новой вершине.
        _next_edge_id (int): Счётчик для автоматического назначения id новому ребру.
    """

    def __init__(self) -> None:
        """
        Инициализирует пустой граф.

        Создаёт пустые словари для вершин и рёбер, инициализирует пустую
        матрицу инцидентности и счётчики id.
        """
        self._vertices: Dict[int, Vertex[T]] = dict()
        self._edges: Dict[int, Edge] = dict()
        self._incidence_matrix: List[List[int]] = []
        self._vertex_order: List[int] = []
        self._edge_order: List[int] = []
        self._next_vertex_id: int = 0
        self._next_edge_id: int = 0

    def __del__(self) -> None:
        """Деструктор."""
        print("Deleting graph")

    def __deepcopy__(self, memo: Dict[int, object]) -> 'Graph[T]':
        """
        Создаёт глубокую копию графа.

        Выполняет полную копию всех данных графа, включая вершины, рёбра,
        матрицу инцидентности и порядки. Параметр memo предотвращает циклические
        ссылки и гарантирует правильность копирования структур с циклами.

        Args:
            memo (Dict[int, object]): Словарь для отслеживания уже скопированных объектов.
                                      Ключ — id оригинального объекта, значение — копия.

        Returns:
            Graph[T]: Новый граф, являющийся глубокой копией текущего.
        """
        new_graph: Graph[T] = Graph()
        memo[id(self)] = new_graph
        new_graph._vertices = copy.deepcopy(self._vertices, memo)
        new_graph._edges = copy.deepcopy(self._edges, memo)
        new_graph._incidence_matrix = copy.deepcopy(self._incidence_matrix, memo)
        new_graph._vertex_order = copy.deepcopy(self._vertex_order, memo)
        new_graph._edge_order = copy.deepcopy(self._edge_order, memo)
        new_graph._next_vertex_id = self._next_vertex_id
        new_graph._next_edge_id = self._next_edge_id
        return new_graph

    @property
    def incidence_matrix(self) -> List[List[int]]:
        """
        Возвращает матрицу инцидентности графа.

        Returns:
            List[List[int]]: Матрица инцидентности (строки — вершины, столбцы — рёбра).
        """
        return self._incidence_matrix

    @property
    def vertex_order(self) -> List[int]:
        """
        Возвращает упорядоченный список id вершин.

        Returns:
            List[int]: Список id вершин в порядке их расположения в матрице.
        """
        return self._vertex_order

    @property
    def edge_order(self) -> List[int]:
        """
        Возвращает упорядоченный список id рёбер.

        Returns:
            List[int]: Список id рёбер в порядке их расположения в матрице.
        """
        return self._edge_order

    def __eq__(self, other: object) -> bool:
        """
        Проверяет равенство двух графов по матрицам инцидентности.

        Args:
            other (object): Объект для сравнения.

        Returns:
            bool: True, если матрицы инцидентности идентичны, иначе False.
        """
        if not isinstance(other, Graph):
            return NotImplemented
        return self._incidence_matrix == other.incidence_matrix

    def __ne__(self, other: object) -> bool:
        """
        Проверяет неравенство двух графов.

        Args:
            other (object): Объект для сравнения.

        Returns:
            bool: True, если графы не равны, иначе False.
        """
        return not self.__eq__(other)

    def __ge__(self, other: 'Graph[T]') -> bool:
        """
        Сравнивает графы по количеству вершин.

        Args:
            other (Graph[T]): Граф для сравнения.

        Returns:
            bool: True, если количество вершин в текущем графе >= количества в other
        """
        return len(self.vertex_order) >= len(other.vertex_order)

    def __gt__(self, other: 'Graph[T]') -> bool:
        """
        Сравнивает графы по количеству вершин.

        Args:
            other (Graph[T]): Граф для сравнения.

        Returns:
            bool: True, если количество вершин в текущем графе > количества в other.
        """
        return len(self.vertex_order) > len(other.vertex_order)

    def __le__(self, other: 'Graph[T]') -> bool:
        """
        Сравнивает графы по количеству вершин.

        Args:
            other (Graph[T]): Граф для сравнения.

        Returns:
            bool: True, если количество вершин в текущем графе <= количества в other.
        """
        return len(self.vertex_order) <= len(other.vertex_order)

    def __lt__(self, other: 'Graph[T]') -> bool:
        """
        Сравнивает графы по количеству вершин.

        Args:
            other (Graph[T]): Граф для сравнения.

        Returns:
            bool: True, если количество вершин в текущем графе < количества в other.
        """
        return len(self.vertex_order) < len(other.vertex_order)

    def __str__(self) -> str:
        """
        Возвращает строковое представление графа.

        Выводит матрицу инцидентности в формате сетки, где каждая строка
        представляет вершину, а каждый столбец — ребро.

        Returns:
            str: Текстовое представление матрицы инцидентности.
        """
        if len(self.vertex_order) == 0:
            return "Graph is empty"
        intro: str = "The graph is represented as an incidence matrix:\n"
        res_matrix: str = ""
        for row in range(len(self._incidence_matrix)):
            for col in range(len(self._incidence_matrix[row])):
                res_matrix += str(self._incidence_matrix[row][col])
                res_matrix += " "
            res_matrix += "\n"
        return intro + res_matrix

    def is_empty(self) -> bool:
        """
        Проверяет, пуст ли граф.

        Returns:
            bool: True, если граф не содержит вершин, иначе False.
        """
        return len(self._vertices) == 0

    def is_vertex_exist(self, vertex: Vertex[T]) -> bool:
        """
        Проверяет наличие вершины в графе.

        Ищет вершину в словаре вершин по значению.

        Args:
            vertex (Vertex[T]): Вершина для поиска.

        Returns:
            bool: True, если такая вершина существует, иначе False.
        """
        for key, value in self._vertices.items():
            if value == vertex:
                return True
        return False

    def is_edge_exist(self, edge: Edge) -> bool:
        """
        Проверяет наличие ребра в графе.

        Ищет ребро в словаре рёбер по значению.

        Args:
            edge (Edge): Ребро для поиска.

        Returns:
            bool: True, если такое ребро существует, иначе False.

        Raises:
            KeyError: Если ребро недействительно.
        """
        for key, value in self._edges.items():
            if value == edge:
                return True
        return False

    def number_of_vertices(self) -> int:
        """
        Возвращает количество вершин в графе.

        Returns:
            int: Количество вершин.
        """
        return len(self._vertices)

    def number_of_edges(self) -> int:
        """
        Возвращает количество рёбер в графе.

        Returns:
            int: Количество рёбер.
        """
        return len(self._edges)

    def vertex_degree(self, id_vertex: int) -> int:
        """
        Возвращает степень вершины (количество инцидентных ей рёбер).

        Степень вершины — это количество рёбер, соединённых с ней.

        Args:
            id_vertex (int): id вершины.

        Returns:
            int: Степень вершины.

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if id_vertex not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        index_of_vertex: int = self._vertex_order.index(id_vertex)
        count_of_not_connected_edges: int = Counter.count_number_in_list(
            self._incidence_matrix[index_of_vertex], 0
        )
        return len(self._incidence_matrix[index_of_vertex]) - count_of_not_connected_edges

    def edge_degree(self, edge_id: int) -> int:
        """
        Возвращает степень ребра.

        Args:
            edge_id (int): id ребра.

        Returns:
            int: Степень ребра.

        Raises:
            IncorrectEdge: Если ребро не существует.
        """
        if edge_id not in self._edges:
            raise IncorrectEdge("Such edge does not exist")
        edge: Edge = self._edges[edge_id]
        v_from_id: int = edge.v_from
        v_to_id: int = edge.v_to
        index_of_from_vertex: int = self._vertex_order.index(v_from_id)
        index_of_to_vertex: int = self._vertex_order.index(v_to_id)
        result_arr_of_from_edges: List[int] = Counter.count_elements_in_list(
            self._incidence_matrix[index_of_from_vertex], POSITIVE_EDGE
        )
        result_arr_of_to_edges: List[int] = Counter.count_elements_in_list(
            self._incidence_matrix[index_of_to_vertex], NEGATIVE_EDGE
        )
        return len(list(set(result_arr_of_from_edges) | set(result_arr_of_to_edges)))

    def add_vertex(self, data: T) -> int:
        """
        Добавляет новую вершину с указанными данными в граф.

        Создаёт объект Vertex с переданными данными, назначает ему уникальный id,
        добавляет новую строку в матрицу инцидентности.

        Args:
            data (T): Данные вершины.

        Returns:
            int: id добавленной вершины.

        Raises:
            IncorrectVertex: Если вершина с такими данными уже существует.
        """
        new_vertex: Vertex[T] = Vertex(data)
        if self.is_vertex_exist(new_vertex):
            raise IncorrectVertex("Such vertex already exist")
        new_vertex.id = self._next_vertex_id
        self._next_vertex_id += 1
        vertex_id: int = new_vertex.id
        self._vertices[vertex_id] = new_vertex
        self._vertex_order.append(vertex_id)
        self._incidence_matrix.append([0] * len(self._edges))
        return vertex_id

    def add_edge(self, vertex_from: int, vertex_to: int) -> int:
        """
        Добавляет новое ребро между двумя вершинами.

        Создаёт ориентированное ребро от vertex_from к vertex_to, добавляет его
        в словарь рёбер и в матрицу инцидентности.

        Args:
            vertex_from (int): id начальной вершины.
            vertex_to (int): id конечной вершины.

        Returns:
            int: id добавленного ребра.

        Raises:
            IncorrectEdge: Если одна из вершин не существует или ребро уже существует.
        """
        if vertex_from not in self._vertices or vertex_to not in self._vertices:
            raise IncorrectEdge("Such edge does not exist")
        edge: Edge = Edge(vertex_from, vertex_to)
        if self.is_edge_exist(edge):
            raise IncorrectEdge("Such edge already exist")
        edge.id = self._next_edge_id
        self._next_edge_id += 1
        self._edges[edge.id] = edge
        self._edge_order.append(edge.id)

        for i, vertex_id in enumerate(self._vertex_order):
            if vertex_id == vertex_from:
                self._incidence_matrix[i].append(POSITIVE_EDGE)  # +1
            elif vertex_id == vertex_to:
                self._incidence_matrix[i].append(NEGATIVE_EDGE)  # -1
            else:
                self._incidence_matrix[i].append(DEFAULT_EDGE)  # 0
        return edge.id

    def remove_edge(self, edge_id: int) -> None:
        """
        Удаляет ребро из графа.

        Удаляет ребро из словаря рёбер и из матрицы инцидентности.

        Args:
            edge_id (int): id удаляемого ребра.

        Raises:
            IncorrectEdge: Если ребро не существует.
        """
        if edge_id not in self._edges:
            raise IncorrectEdge("Such edge does not exist")

        index_of_edge: int = self._edge_order.index(edge_id)
        self._edge_order.pop(index_of_edge)

        for i in range(len(self._incidence_matrix)):
            self._incidence_matrix[i].pop(index_of_edge)
        del self._edges[edge_id]

    def remove_vertex(self, vertex_id: int) -> None:
        """
        Удаляет вершину из графа.

        Удаляет вершину и все инцидентные ей рёбра. Сначала удаляются
        все рёбра, соединённые с вершиной, а затем сама вершина.

        Args:
            vertex_id (int): id удаляемой вершины.

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")

        list_of_edges: List[int] = []
        index_of_vertex: int = self._vertex_order.index(vertex_id)
        for i in range(len(self._edge_order)):
            element: int = self._incidence_matrix[index_of_vertex][i]
            if element == POSITIVE_EDGE or element == NEGATIVE_EDGE:
                list_of_edges.append(self._edge_order[i])

        for edge_id in list_of_edges:
            self.remove_edge(edge_id)

        self._vertex_order.pop(index_of_vertex)
        self._incidence_matrix.pop(index_of_vertex)
        del self._vertices[vertex_id]

    def clear(self) -> None:
        """Полная очистка графа."""
        self._vertices.clear()
        self._edges.clear()
        self._incidence_matrix = []
        self._vertex_order = []
        self._edge_order = []
        self._next_vertex_id = 0
        self._next_edge_id = 0

    def bidirectional_iterator_for_iterating_over_vertices(self) -> BidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт двусторонний итератор для обхода вершин в прямом порядке.

        Returns:
            BidirectionalVertexAndEdgeIterator[T]: Итератор для вершин
        """
        return BidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order)

    def reverse_bidirectional_iterator_for_iterating_over_vertices(self) -> BidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт двусторонний итератор для обхода вершин в обратном порядке.

        Returns:
            BidirectionalVertexAndEdgeIterator[T]: Итератор для вершин (обратный)
        """
        return BidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order, reverse=True)

    def const_bidirectional_iterator_for_iterating_over_vertices(self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода вершин в прямом порядке.

        Returns:
            ConstBidirectionalVertexAndEdgeIterator[T]: Константный итератор для вершин.
        """
        return ConstBidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order)

    def const_reverse_bidirectional_iterator_for_iterating_over_vertices(
            self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода вершин в обратном порядке.

        Returns:
            ConstBidirectionalVertexAndEdgeIterator[T]: Константный итератор для вершин (обратный).
        """
        return ConstBidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order, reverse=True)

    def bidirectional_iterator_for_traversing_edges(self) -> BidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт двусторонний итератор для обхода рёбер в прямом порядке.

        Returns:
            BidirectionalVertexAndEdgeIterator[T]: Итератор для рёбер.
        """
        return BidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order)

    def reverse_bidirectional_iterator_for_traversing_edges(self) -> BidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт двусторонний итератор для обхода рёбер в обратном порядке.

        Returns:
            BidirectionalVertexAndEdgeIterator[T]: Итератор для рёбер (обратный).
        """
        return BidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order, reverse=True)

    def const_bidirectional_iterator_for_traversing_edges(self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода рёбер в прямом порядке.

        Returns:
            ConstBidirectionalVertexAndEdgeIterator[T]: Константный итератор для рёбер.
        """
        return ConstBidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order)

    def const_reverse_bidirectional_iterator_for_traversing_edges(
            self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода рёбер в обратном порядке.

        Returns:
            ConstBidirectionalVertexAndEdgeIterator[T]: Константный итератор для рёбер (обратный).
        """
        return ConstBidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order, reverse=True)

    def bidirectional_iterator_for_iter_over_edges_incident_to_vertex(
            self, vertex_id: int) -> BidirectionalIncidentEdgesIterator[T]:
        """
        Создаёт двусторонний итератор для обхода рёбер, инцидентных вершине, в прямом порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            BidirectionalIncidentEdgesIterator[T]: Итератор для инцидентных рёбер.

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return BidirectionalIncidentEdgesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertex_order, vertex_id
        )

    def reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(
            self, vertex_id: int) -> BidirectionalIncidentEdgesIterator[T]:
        """
        Создаёт двусторонний итератор для обхода рёбер, инцидентных вершине, в обратном порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            BidirectionalIncidentEdgesIterator[T]: Итератор для инцидентных рёбер (обратный).

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return BidirectionalIncidentEdgesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertex_order, vertex_id, reverse=True
        )

    def const_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(
            self, vertex_id: int) -> ConstBidirectionalIncidentEdgesIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода рёбер, инцидентных вершине, в прямом порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            ConstBidirectionalIncidentEdgesIterator[T]: Константный итератор для инцидентных рёбер.

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return ConstBidirectionalIncidentEdgesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertex_order, vertex_id
        )

    def const_reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(
            self, vertex_id: int) -> ConstBidirectionalIncidentEdgesIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода рёбер, инцидентных вершине, в обратном порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            ConstBidirectionalIncidentEdgesIterator[T]: Константный итератор для инцидентных рёбер (обратный).

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return ConstBidirectionalIncidentEdgesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertex_order, vertex_id, reverse=True
        )

    def bidirectional_iterator_over_vertices_adjacent_to_vertex(
            self, vertex_id: int) -> BidirectionalAdjacentVerticesIterator[T]:
        """
        Создаёт двусторонний итератор для обхода вершин, смежных с данной, в прямом порядке.

        Смежные вершины — это вершины, соединённые ребром с данной вершиной.

        Args:
            vertex_id (int): id вершины.

        Returns:
            BidirectionalAdjacentVerticesIterator[T]: Итератор для смежных вершин.

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return BidirectionalAdjacentVerticesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertices, self._vertex_order, vertex_id
        )

    def reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex(
            self, vertex_id: int) -> BidirectionalAdjacentVerticesIterator[T]:
        """
        Создаёт двусторонний итератор для обхода вершин, смежных с данной, в обратном порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            BidirectionalAdjacentVerticesIterator[T]: Итератор для смежных вершин (обратный).

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return BidirectionalAdjacentVerticesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertices, self._vertex_order, vertex_id, reverse=True
        )

    def const_bidirectional_iterator_over_vertices_adjacent_to_vertex(
            self, vertex_id: int) -> ConstBidirectionalAdjacentVerticesIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода вершин, смежных с данной, в прямом порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            ConstBidirectionalAdjacentVerticesIterator[T]: Константный итератор для смежных вершин.

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return ConstBidirectionalAdjacentVerticesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertices, self._vertex_order, vertex_id
        )

    def const_reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex(
            self, vertex_id: int) -> ConstBidirectionalAdjacentVerticesIterator[T]:
        """
        Создаёт константный двусторонний итератор для обхода вершин, смежных с данной, в обратном порядке.

        Args:
            vertex_id (int): id вершины.

        Returns:
            ConstBidirectionalAdjacentVerticesIterator[T]: Константный итератор для смежных вершин (обратный).

        Raises:
            IncorrectVertex: Если вершина не существует.
        """
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        return ConstBidirectionalAdjacentVerticesIterator[T](
            self._incidence_matrix, self._edge_order, self._edges,
            self._vertices, self._vertex_order, vertex_id, reverse=True
        )

    def remove_vertex_by_iterator(self, iterator: BidirectionalVertexAndEdgeIterator[T]) -> None:
        """
        Удаляет вершину, на которую указывает текущая позиция итератора.

        Args:
            iterator (BidirectionalVertexAndEdgeIterator[T]): Итератор, позиция которого указывает на вершину.

        Raises:
            Exception: Если итератор позиционирован на рёбро вместо вершины.
        """
        current_vertex: int = iterator.current_element()
        if isinstance(self._vertices[current_vertex], Edge):
            raise Exception("Incorrect type of iterator, now you choose iterator for edges")
        self.remove_vertex(current_vertex)

    def remove_edge_by_iterator(self, iterator: BidirectionalVertexAndEdgeIterator[T]) -> None:
        """
        Удаляет ребро, на которое указывает текущая позиция итератора.

        Args:
            iterator (BidirectionalVertexAndEdgeIterator[T]): Итератор, позиция которого указывает на ребро.

        Raises:
            Exception: Если итератор позиционирован на вершину вместо ребра.
        """
        current_edge: int = iterator.current_element()
        if not isinstance(self._edges[current_edge], Edge):
            raise Exception("Incorrect type of iterator, now you choose iterator for Vertex")
        self.remove_edge(current_edge)
