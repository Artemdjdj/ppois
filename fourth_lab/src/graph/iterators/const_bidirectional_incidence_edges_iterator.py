from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIteratorForIncidentEdges
from typing import List, Self


class ConstBidirectionalIncidentEdgesIterator(BidirectionalIteratorForIncidentEdges):
    __slots__ = ()

    def __init__(self, matrix: List[List[int]], order_edges: List[int], order_vertex: List[int], vertex_id: int,
                 reverse: bool = False):
        object.__setattr__(self, '_matrix', matrix)
        object.__setattr__(self, '_order_edges', order_edges)
        object.__setattr__(self, '_order_vertex', order_vertex)
        object.__setattr__(self, '_vertex_id', vertex_id)
        object.__setattr__(self, '_vertex', order_vertex.index(vertex_id))
        object.__setattr__(self, '_current_edge', len(matrix[0]) - 1 if reverse else 0)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        return ConstBidirectionalIncidentEdgesIterator(
            self._matrix,
            self._order_edges,
            self._order_vertex,
            self._vertex_id,
            self._reverse
        )

    def __setattr__(self, name: str, value):
        raise AttributeError(
            f"Константный итератор защищен, атрибут '{name}' нельзя изменить."
        )
