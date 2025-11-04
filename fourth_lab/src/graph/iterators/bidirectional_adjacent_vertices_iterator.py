from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIteratorForIncidentEdges
from src.graph.edge import Edge
from typing import List, Dict, Self


class BidirectionalAdjacentVerticesIterator(BidirectionalIteratorForIncidentEdges):
    __slots__ = ('_edges',)

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge], order_vertex: List[int],
                 vertex_id: int, reverse: bool = False) -> None:
        super().__init__(matrix, order_edges, order_vertex, vertex_id, reverse)
        self._edges = edges

    def __iter__(self) -> Self:
        return self

    def __next__(self) -> int:
        edge_id = super().__next__()
        edge = self._edges[edge_id]
        v_from = edge.v_from
        v_to = edge.v_to
        return v_from if v_to == self._vertex_id else v_to

    def previous(self) -> int:
        edge_id = super().previous()
        edge = self._edges[edge_id]
        v_from = edge.v_from
        v_to = edge.v_to
        return v_from if v_to == self._vertex_id else v_to
