from src.graph.iterators.bidirectional_adjacent_vertices_iterator import BidirectionalAdjacentVerticesIterator
from src.graph.edge import Edge
from typing import List, Dict, Self, Generic, TypeVar
from src.graph.vertex import Vertex

T = TypeVar('T')


class ConstBidirectionalAdjacentVerticesIterator(BidirectionalAdjacentVerticesIterator[T], Generic[T]):
    __slots__ = ()

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 vertices: Dict[int, Vertex[T]], order_vertex: List[int],
                 vertex_id: int, reverse: bool = False) -> None:
        object.__setattr__(self, '_matrix', matrix)
        object.__setattr__(self, '_order_edges', order_edges)
        object.__setattr__(self, '_edges', edges)
        object.__setattr__(self, '_vertices', vertices)
        object.__setattr__(self, '_order_vertex', order_vertex)
        object.__setattr__(self, '_vertex_id', vertex_id)
        object.__setattr__(self, '_vertex', order_vertex.index(vertex_id))
        object.__setattr__(self, '_current_edge', len(matrix[0]) - 1 if reverse else 0)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        return ConstBidirectionalAdjacentVerticesIterator[T](
            self._matrix,
            self._order_edges,
            self._edges,
            self._vertices,
            self._order_vertex,
            self._vertex_id,
            self._reverse
        )

    def __setattr__(self, name: str, value) -> None:
        raise AttributeError(
            f"Constant iterator is protected, attribute '{name}' is changed."
        )
