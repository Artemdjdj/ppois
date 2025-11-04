"""Файл graph.py необходим для определения класса контейнера (графа)."""
from src.graph.settings import POSITIVE_EDGE, NEGATIVE_EDGE, DEFAULT_EDGE
from vertex import Vertex
from edge import Edge
from typing import Generic, TypeVar, List, Set, Tuple, Hashable, Dict
from exceptions.exceptions import IncorrectVertex, IncorrectEdge, IncorrectPosition
from src.graph.iterators.bidirectional_adjacent_vertices_iterator import BidirectionalAdjacentVerticesIterator
from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIncidentEdgesIterator
from src.graph.iterators.bidirectional_vertex_and_edge_iterator import BidirectionalVertexAndEdgeIterator
from src.graph.iterators.const_bidirection_adjacent_vertices_iterator import ConstBidirectionalAdjacentVerticesIterator
from src.graph.iterators.const_bidirectional_incidence_edges_iterator import ConstBidirectionalIncidentEdgesIterator
from src.graph.iterators.const_bidirectional_vertex_and_edge_iterator import ConstBidirectionalVertexAndEdgeIterator
from utils import Counter
from settings import *
import copy

T = TypeVar('T', bound=Hashable)


class Graph(Generic[T]):
    """Контейнер (граф)

    Граф представлен с помощью матрицы инцидентности, также хранятся специальные
    словари вершин и ребер, и карты для быстрой работы котнейнера. В контейнере
    реализованы все необходимые методы.

    Attributes:
        vertices (Dict[int, Vertex[T]]): Словарь, в котором ключ id  вершины, а значение - вершина
        edges (Dict[int, Edge]): Словарь, в котором ключ id ребра, а значение - ребро
        incidence_matrix (List[List[int]]): Матрица инцидентности
        vertex_order (List[int]): Список id вершин как в матрице ницидентности (строки)
        edge_order (List[int]): Список id ребер как в матрице ницидентности (столбцы)
    """
    setup_logger()
    _logger = logging.getLogger(__name__)

    def __init__(self):
        self._vertices: Dict[int, Vertex[T]] = dict()
        self._edges: Dict[int, Edge] = dict()
        self._incidence_matrix: List[List[int]] = []
        self._vertex_order: List[int] = []
        self._edge_order: List[int] = []

    def __del__(self, ) -> None:
        Graph._logger.debug("Deleting graph")

    def __copy__(self):
        new_graph = Graph()
        new_graph._vertices = self._vertices.copy()
        new_graph._edges = self._edges.copy()
        new_graph._incidence_matrix = [row[:] for row in self._incidence_matrix]
        new_graph._vertex_order = self._vertex_order.copy()
        new_graph._edge_order = self._edge_order.copy()
        return new_graph

    def __deepcopy__(self, memo):
        new_graph = Graph()
        new_graph._vertices = copy.deepcopy(self._vertices, memo)
        new_graph._edges = copy.deepcopy(self._edges, memo)
        self._incidence_matrix = copy.deepcopy(self._incidence_matrix, memo)
        new_graph._vertex_order = copy.deepcopy(self._vertex_order, memo)
        new_graph._edge_order = copy.deepcopy(self._edge_order, memo)
        memo[id(self)] = new_graph
        return new_graph

    @property
    def incidence_matrix(self) -> List[List[int]]:
        return self._incidence_matrix

    @property
    def vertex_order(self) -> List[int]:
        return self._vertex_order

    def __eq__(self, other):
        return self._incidence_matrix == other.incidence_matrix

    def __ne__(self, other):
        return not self.__eq__(other)

    def __ge__(self, other):
        return len(self.vertex_order) >= len(other.vertex_order)

    def __gt__(self, other):
        return len(self.vertex_order) > len(other.vertex_order)

    def __le__(self, other):
        return not self.__ge__(other)

    def __lt__(self, other):
        return not self.__gt__(other)

    def __str__(self):
        if len(self.vertex_order) == 0:
            return "Graph is empty"
        intro = f"The graph is represented as an incidence matrix:\n"
        res_matrix = ""
        for row in range(len(self._incidence_matrix)):
            for col in range(len(self._incidence_matrix[row])):
                res_matrix += str(self._incidence_matrix[row][col])
                res_matrix += " "
            res_matrix += "\n"
        return intro + res_matrix

    def is_empty(self) -> bool:
        return len(self._vertices) == 0

    def clear(self):
        self._vertices.clear()
        self._edges.clear()
        self._incidence_matrix = []

    def is_vertex_exist(self, id_vertex: int) -> bool:
        return id_vertex in self._vertices

    def is_edge_exist(self, id_edge: int) -> bool:
        return id_edge in self._edges

    def number_of_vertices(self) -> int:
        return len(self._vertices)

    def number_of_edges(self) -> int:
        return len(self._edges)

    def vertex_degree(self, id_vertex: int) -> int:
        if id_vertex not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")
        index_of_vertex = self._vertex_order.index(id_vertex)
        count_of_not_connected_edges = Counter.count_number_in_list(self._incidence_matrix[index_of_vertex], 0)
        return len(self._incidence_matrix[index_of_vertex]) - count_of_not_connected_edges

    def edge_degree(self, edge_id: int) -> int:
        if edge_id not in self._edges:
            raise IncorrectEdge("Such edge does not exist")
        edge = self._edges[edge_id]
        v_from_id = edge.v_from
        v_to_id = edge.v_to
        index_of_from_vertex = self._vertex_order.index(v_from_id)
        index_of_to_vertex = self._vertex_order.index(v_to_id)
        result_arr_of_from_edges = Counter.count_elements_in_list(self._incidence_matrix[index_of_from_vertex], 1)
        result_arr_of_to_edges = Counter.count_elements_in_list(self._incidence_matrix[index_of_to_vertex], -1)
        return len(list(set(result_arr_of_from_edges) | set(result_arr_of_to_edges)))

    def add_vertex(self, data: T) -> int:
        new_vertex = Vertex(data)
        vertex_id = new_vertex.id
        self._vertices[vertex_id] = new_vertex
        self._vertex_order.append(vertex_id)
        self._incidence_matrix.append([0] * len(self._edges))
        return vertex_id

    def add_edge(self, vertex_from: int, vertex_to) -> None:
        if vertex_from not in self._vertices or vertex_to not in self._vertices:
            raise IncorrectEdge("Such edge does not exist")

        edge = Edge(vertex_from, vertex_to)
        edge_id = edge.id
        self._edges[edge_id] = edge
        self._edge_order.append(edge_id)

        for i, vertex_id in enumerate(self._vertex_order):
            if vertex_id == vertex_from:
                self._incidence_matrix[i].append(POSITIVE_EDGE)
            elif vertex_id == vertex_to:
                self._incidence_matrix[i].append(NEGATIVE_EDGE)
            else:
                self._incidence_matrix[i].append(DEFAULT_EDGE)

    def remove_edge(self, edge_id: int) -> None:
        if edge_id not in self._edges:
            raise IncorrectEdge("Such edge does not exist")

        index_of_edge = self._edge_order.index(edge_id)
        self._edge_order.pop(index_of_edge)

        for i in range(len(self._incidence_matrix)):
            self._incidence_matrix[i].pop(index_of_edge)
        del self._edges[edge_id]

    def remove_vertex(self, vertex_id: int) -> None:
        if vertex_id not in self._vertices:
            raise IncorrectVertex("Such vertex does not exist")

        list_of_edges = []
        index_of_vertex = self._vertex_order.index(vertex_id)
        for i in range(len(self._edge_order)):
            element = self._incidence_matrix[index_of_vertex][i]
            if element == POSITIVE_EDGE or element == NEGATIVE_EDGE:
                list_of_edges.append(self._edge_order[i])

        for edge_id in list_of_edges:
            self.remove_edge(edge_id)

        self._vertex_order.pop(index_of_vertex)
        self._incidence_matrix.pop(index_of_vertex)
        del self._vertices[vertex_id]

    def bidirectional_iterator_for_iterating_over_vertices(self) -> BidirectionalVertexAndEdgeIterator[T]:
        return BidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order)

    def reverse_bidirectional_iterator_for_iterating_over_vertices(self) -> BidirectionalVertexAndEdgeIterator[T]:
        return BidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order, reverse=True)

    def const_bidirectional_iterator_for_iterating_over_vertices(self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        return ConstBidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order)

    def const_reverse_bidirectional_iterator_for_iterating_over_vertices(self) -> \
            ConstBidirectionalVertexAndEdgeIterator[T]:
        return ConstBidirectionalVertexAndEdgeIterator[T](self._vertices, self._vertex_order, reverse=True)

    def bidirectional_iterator_for_traversing_edges(self) -> BidirectionalVertexAndEdgeIterator[T]:
        return BidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order)

    def reverse_bidirectional_iterator_for_traversing_edges(self) -> BidirectionalVertexAndEdgeIterator[T]:
        return BidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order, reverse=True)

    def const_bidirectional_iterator_for_traversing_edges(self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        return ConstBidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order)

    def const_reverse_bidirectional_iterator_for_traversing_edges(self) -> ConstBidirectionalVertexAndEdgeIterator[T]:
        return ConstBidirectionalVertexAndEdgeIterator[T](self._edges, self._edge_order, reverse=True)

    def bidirectional_iterator_for_iter_over_edges_incident_to_vertex(self, vertex_id: int) -> \
            BidirectionalIncidentEdgesIterator[T]:
        return BidirectionalIncidentEdgesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                     self._vertex_order,
                                                     vertex_id)

    def reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(self, vertex_id: int) -> \
            BidirectionalIncidentEdgesIterator[T]:
        return BidirectionalIncidentEdgesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                     self._vertex_order,
                                                     vertex_id, reverse=True)

    def const_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(self, vertex_id: int) -> \
            ConstBidirectionalIncidentEdgesIterator[T]:
        return ConstBidirectionalIncidentEdgesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                          self._vertex_order,
                                                          vertex_id)

    def const_reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(self, vertex_id: int) -> \
            ConstBidirectionalIncidentEdgesIterator[T]:
        return ConstBidirectionalIncidentEdgesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                          self._vertex_order,
                                                          vertex_id, reverse=True)

    def bidirectional_iterator_over_vertices_adjacent_to_vertex(self, vertex_id: int) -> \
            BidirectionalAdjacentVerticesIterator[T]:
        return BidirectionalAdjacentVerticesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                        self._vertices,
                                                        self._vertex_order,
                                                        vertex_id)

    def reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex(self, vertex_id: int) -> \
            BidirectionalAdjacentVerticesIterator[T]:
        return BidirectionalAdjacentVerticesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                        self._vertices,
                                                        self._vertex_order,
                                                        vertex_id, reverse=True)

    def const_bidirectional_iterator_over_vertices_adjacent_to_vertex(self, vertex_id: int) -> \
            ConstBidirectionalAdjacentVerticesIterator[T]:
        return ConstBidirectionalAdjacentVerticesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                             self._vertices,
                                                             self._vertex_order,
                                                             vertex_id)

    def const_reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex(self, vertex_id: int) -> \
            ConstBidirectionalAdjacentVerticesIterator[T]:
        return ConstBidirectionalAdjacentVerticesIterator[T](self._incidence_matrix, self._edge_order, self._edges,
                                                             self._vertices,
                                                             self._vertex_order,
                                                             vertex_id, reverse=True)

    def remove_vertex_by_iterator(self, iterator: BidirectionalVertexAndEdgeIterator[T]) -> None:
        current_vertex = iterator.current_element()
        if isinstance(current_vertex, Edge):
            raise Exception("Incorrect type of iterator, now you choose iterator for edges")
        self.remove_vertex(current_vertex.id)

    def remove_edge_by_iterator(self, iterator: BidirectionalVertexAndEdgeIterator[T]) -> None:
        current_edge = iterator.current_element()
        if not isinstance(current_edge, Edge):
            raise Exception("Incorrect type of iterator, now you choose iterator for Vertex")
        self.remove_edge(current_edge.id)
