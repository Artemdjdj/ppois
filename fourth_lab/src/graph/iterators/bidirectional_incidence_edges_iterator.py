from src.graph.exceptions.exceptions import EmptyContainer
from src.graph.edge import Edge
from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from typing import TypeVar, List, Self, Dict, Generic

T = TypeVar('T')


class BidirectionalIncidentEdgesIterator(IBidirectionalBaseIterator, Generic[T]):
    __slots__ = ('_matrix', '_edges', '_order_edges', '_order_vertex', '_vertex_id', '_vertex', '_current_edge',
                 '_reverse')

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 order_vertex: List[int], vertex_id: int, reverse: bool = False) -> None:
        self._matrix = matrix
        self._edges = edges
        self._order_edges = order_edges
        self._order_vertex = order_vertex
        self._vertex_id = vertex_id
        self._vertex = self._order_vertex.index(vertex_id)
        self._current_edge = len(matrix[0]) - 1 if reverse else 0
        self._reverse = reverse

    def __iter__(self) -> Self:
        return self

    def is_incident_edge(self) -> bool:
        return self._matrix[self._vertex][self._current_edge] != 0

    @property
    def current_edge(self)->int:
        return self._current_edge

    @current_edge.setter
    def current_edge(self, new_edge: int) -> None:
        self._current_edge = new_edge

    def __set_current_edge(self, value: int) -> None:
        object.__setattr__(self, '_current_edge', value)

    def __next__(self) -> Edge:
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
        if len(self._matrix) == 0:
            raise EmptyContainer("Matrix empty")
        if not self._reverse:
            return self._current_edge < len(self._matrix[0])
        return self._current_edge >= 0

    def has_previous(self) -> bool:
        if len(self._matrix) == 0:
            raise EmptyContainer("Matrix empty")
        if not self._reverse:
            return self._current_edge >= 0
        return self._current_edge < len(self._matrix[0])
