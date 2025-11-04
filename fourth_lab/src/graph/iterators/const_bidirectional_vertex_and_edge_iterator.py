from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from src.graph.iterators.bidirectional_vertex_and_edge_iterator import BidirectionalVertexAndEdgeIterator
from typing import TypeVar, List, Self, Tuple


class ConstBidirectionalVertexAndEdgeIterator(BidirectionalVertexAndEdgeIterator):
    __slots__ = ('_collection', '_position', '_reverse')

    def __init__(self, collection: List[int], reverse: bool = False) -> None:
        object.__setattr__(self, '_collection', tuple(collection))
        object.__setattr__(self, '_position', 0 if not reverse else len(collection) - 1)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        return ConstBidirectionalVertexAndEdgeIterator(
            self._collection,
            reverse=self._reverse
        )

    def __setattr__(self, name: str, value) -> None:
        raise AttributeError(
            f"Константный итератор защищен, атрибут '{name}' нельзя изменить."
        )
