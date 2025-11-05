"""Файл bidirectional_incidence_edges_iterator.py для определения логики итератора по ребрам инцидентным вершине."""

from src.graph.exceptions.exceptions import EmptyContainer
from src.graph.edge import Edge
from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from typing import TypeVar, List, Self, Dict, Generic

T = TypeVar('T')


class BidirectionalIncidentEdgesIterator(IBidirectionalBaseIterator, Generic[T]):
    """
    Двусторонний итератор для обхода рёбер, инцидентных заданной вершине.

    Attributes:
        _matrix (List[List[int]]): Матрица инцидентности графа.
        _edges (Dict[int, Edge]): Словарь рёбер графа.
        _order_edges (List[int]): Упорядоченный список ID рёбер.
        _order_vertex (List[int]): Упорядоченный список ID вершин.
        _vertex_id (int): ID вершины, для которой ищем инцидентные рёбра.
        _vertex (int): Индекс вершины в матрице инцидентности.
        _current_edge (int): Текущая позиция в списке рёбер.
        _reverse (bool): Флаг обратного направления обхода.
    """
    __slots__ = ('_matrix', '_edges', '_order_edges', '_order_vertex', '_vertex_id', '_vertex', '_current_edge',
                 '_reverse')

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 order_vertex: List[int], vertex_id: int, reverse: bool = False) -> None:
        """
        Инициализирует итератор по инцидентным рёбрам.

        Args:
            matrix (List[List[int]]): Матрица инцидентности графа.
            order_edges (List[int]): Упорядоченный список ID рёбер (порядок столбцов).
            edges (Dict[int, Edge]): Словарь всех рёбер графа.
            order_vertex (List[int]): Упорядоченный список ID вершин (порядок строк).
            vertex_id (int): ID вершины, для которой ищем инцидентные рёбра.
            reverse (bool, optional): Если True, начинать с конца, изначально False.
        """
        self._matrix = matrix
        self._edges = edges
        self._order_edges = order_edges
        self._order_vertex = order_vertex
        self._vertex_id = vertex_id
        self._vertex = self._order_vertex.index(vertex_id)
        self._current_edge = len(matrix[0]) - 1 if reverse else 0
        self._reverse = reverse

    def __iter__(self) -> Self:
        """
        Возвращает сам итератор.

        Returns:
            Self: Этот же итератор.
        """
        return self

    def is_incident_edge(self) -> bool:
        """
        Проверяет, является ли текущее ребро инцидентным вершине.

        Returns:
            bool: True, если текущее ребро инцидентно, False — нет.
        """
        return self._matrix[self._vertex][self._current_edge] != 0

    @property
    def current_edge(self) -> int:
        """
        Возвращает индекс текущего ребра.

        Returns:
            int: Индекс текущего ребра в списке order_edges.
        """
        return self._current_edge

    @current_edge.setter
    def current_edge(self, new_edge: int) -> None:
        """
        Устанавливает новый индекс текущего ребра.

        Args:
            new_edge (int): Новый индекс ребра.
        """
        self._current_edge = new_edge

    def __set_current_edge(self, value: int) -> None:
        """
        Внутренний метод для изменения _current_edge.

        Args:
            value (int): Новое значение индекса ребра.
        """
        object.__setattr__(self, '_current_edge', value)

    def __next__(self) -> Edge:
        """
        Возвращает следующее инцидентное ребро и переходит вперёд.

        Returns:
            Edge: Следующее инцидентное ребро.

        Raises:
            StopIteration: Когда больше нет инцидентных рёбер.
            EmptyContainer: Если граф не содержит рёбер.
        """
        if not self._reverse:
            while self.has_next() and not self.is_incident_edge():
                self.__set_current_edge(self._current_edge + 1)

            if not self.has_next():
                raise StopIteration

            res_edge = self._current_edge
            self.__set_current_edge(self._current_edge + 1)
            result = self._order_edges[res_edge]
            return self._edges[result]

        while self.has_next() and not self.is_incident_edge():
            self.__set_current_edge(self._current_edge - 1)

        if not self.has_next():
            raise StopIteration
        res_edge = self._current_edge
        self.__set_current_edge(self._current_edge - 1)

        result = self._order_edges[res_edge]
        return self._edges[result]

    def previous(self) -> Edge:
        """
        Возвращает предыдущее инцидентное ребро и переходит назад.

        Returns:
            Edge: Предыдущее инцидентное ребро.

        Raises:
            StopIteration: Когда нет предыдущих инцидентных рёбер.
            EmptyContainer: Если граф не содержит рёбер.
        """
        if not self._reverse:
            self.__set_current_edge(self._current_edge - 1)

            while self.has_previous() and not self.is_incident_edge():
                self.__set_current_edge(self._current_edge - 1)

            if self._current_edge < 0:
                raise StopIteration

            result = self._order_edges[self._current_edge]
            return self._edges[result]

        self.__set_current_edge(self._current_edge + 1)

        while self.has_previous() and not self.is_incident_edge():
            self.__set_current_edge(self._current_edge + 1)

        if self._current_edge >= len(self._matrix[0]):
            raise StopIteration

        result = self._order_edges[self._current_edge]
        return self._edges[result]

    def has_next(self) -> bool:
        """
        Проверяет наличие следующего инцидентного ребра.

        Returns:
            bool: True, если есть следующее ребро, False — нет.

        Raises:
            EmptyContainer: Если граф не содержит рёбер.
        """
        if len(self._edges) == 0:
            raise EmptyContainer("There are no any edges")
        if not self._reverse:
            return self._current_edge < len(self._edges)
        return self._current_edge >= 0

    def has_previous(self) -> bool:
        """
        Проверяет наличие предыдущего инцидентного ребра.

        Returns:
            bool: True, если есть предыдущее ребро, False — нет.

        Raises:
            EmptyContainer: Если граф не содержит рёбер.
        """
        if len(self._edges) == 0:
            raise EmptyContainer("There are no any edges")
        if not self._reverse:
            return self._current_edge >= 0
        return self._current_edge < len(self._edges)
