from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from typing import TypeVar, List, Self
from src.graph.edge import Edge

T = TypeVar('T')

class EdgeBidirectionalIterator(IBidirectionalBaseIterator):
    def __init__(self, collection:List[Edge], position = 0):
        self._collections = collection
        self._position = position if position >= 0 else 0

    @property
    def position(self) -> int:
        return self._position

    def __iter__(self)->Self:
        return self

    def __next__(self)->Edge:
        if not self.has_next():
            raise StopIteration
        edge = self._collections[self._position]
        self._position += 1
        return edge

    def previous(self)->Edge:
        if not self.has_previous():
            raise StopIteration
        edge = self._collections[self._position]
        self._position -= 1
        return edge

    def has_next(self) -> bool:
        return self._position < len(self._collections)

    def has_previous(self) -> bool:
        return self._position >= 0


