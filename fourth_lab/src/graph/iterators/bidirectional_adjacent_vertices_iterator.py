from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIncidentEdgesIterator
from src.graph.edge import Edge
from src.graph.vertex import Vertex
from typing import TypeVar, List, Dict, Self, Generic

T = TypeVar('T')


class BidirectionalAdjacentVerticesIterator(BidirectionalIncidentEdgesIterator[T], Generic[T]):
    __slots__ = ('_vertices',)

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 vertices: Dict[int, Vertex[T]], order_vertex: List[int],
                 vertex_id: int, reverse: bool = False) -> None:
        super().__init__(matrix, order_edges, edges, order_vertex, vertex_id, reverse)
        self._vertices = vertices

    def __iter__(self) -> Self:
        return self

    def __next__(self) -> Vertex[T]:
        edge = super().__next__()
        v_from = edge.v_from
        v_to = edge.v_to
        res_v_id = v_from if v_to == self._vertex_id else v_to
        return self._vertices[res_v_id]

    def previous(self) -> Vertex[T]:
        edge = super().previous()
        v_from = edge.v_from
        v_to = edge.v_to
        res_v_id = v_from if v_to == self._vertex_id else v_to
        return self._vertices[res_v_id]
