from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from typing import TypeVar, List, Self

T = TypeVar('T')


class BidirectionalVertexAndEdgeIterator(IBidirectionalBaseIterator):
    def __init__(self, collection: List[int], reverse: bool = False) -> None:
        self._collection = collection
        self._position = 0 if not reverse else len(collection) - 1
        self._reverse = reverse

    @property
    def position(self) -> int:
        return self._position

    def _set_position(self, value: int) -> None:
        object.__setattr__(self, '_position', value)

    def __iter__(self) -> Self:
        return self

    def __next__(self) -> int:
        if not self._reverse:
            if not self.has_next():
                raise StopIteration
            result = self._collection[self._position]
            self._set_position(self._position + 1)
            return result
        if not self.has_next():
            raise StopIteration
        result = self._collection[self._position]
        self._set_position(self._position - 1)
        return result

    def previous(self) -> int:
        if not self._reverse:
            if not self.has_previous():
                raise StopIteration
            self._set_position(self._position - 1)
            return self._collection[self._position]
        if not self.has_previous():
            raise StopIteration
        self._set_position(self._position + 1)
        return self._collection[self._position]

    def has_next(self) -> bool:
        if not self._reverse:
            return self._position < len(self._collection)
        return self.position >= 0

    def has_previous(self) -> bool:
        if not self._reverse:
            return self._position > 0
        return self._position < len(self._collection) - 1
