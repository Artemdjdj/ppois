from src.graph.settings import POSITIVE_EDGE, NEGATIVE_EDGE, DEFAULT_EDGE
from vertex import Vertex
from edge import Edge
from typing import Generic, TypeVar, List, Set, Tuple, Hashable, Dict
from exceptions.exceptions import IncorrectVertex, IncorrectEdge
from utils import Counter
from settings import *
import copy

T = TypeVar('T', bound=Hashable)


class Graph(Generic[T]):
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
