from src.graph.exceptions.exceptions import IncorrectPosition
from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from src.graph.vertex import Vertex
from src.graph.edge import Edge
from typing import TypeVar, List, Self, Union, Dict, Generic

T = TypeVar('T')


class BidirectionalVertexAndEdgeIterator(IBidirectionalBaseIterator, Generic[T]):
    __slots__ = ('_collection', '_order_list', '_position', '_reverse')

    def __init__(self, collection: Union[Dict[int, Vertex[T]], Dict[int, Edge]], order_list: List[int],
                 reverse: bool = False) -> None:
        self._collection = collection
        self._order_list = order_list
        self._position = 0 if not reverse else len(collection) - 1
        self._reverse = reverse

    @property
    def position(self) -> int:
        return self._position

    @position.setter
    def position(self, position: int) -> None:
        self._position = position

    def current_element(self) -> int:
        if self._position < 0 or self._position >= len(self._order_list):
            raise IncorrectPosition("Iterator out of bounds")
        return self._order_list[self._position]

    def __set_position(self, value: int) -> None:
        object.__setattr__(self, '_position', value)

    def __iter__(self) -> Self:
        return self

    def __next__(self) -> Union[Vertex[T], Edge]:
        if not self._reverse:
            if not self.has_next():
                raise StopIteration
            result = self._order_list[self._position]
            self.__set_position(self._position + 1)
            return self._collection[result]
        if not self.has_next():
            raise StopIteration
        result = self._order_list[self._position]
        self.__set_position(self._position - 1)
        return self._collection[result]

    def previous(self) -> Union[Vertex[T], Edge]:
        if not self._reverse:
            if not self.has_previous():
                raise StopIteration
            self.__set_position(self._position - 1)
            result = self._order_list[self._position]
            return self._collection[result]
        if not self.has_previous():
            raise StopIteration
        self.__set_position(self._position + 1)
        result = self._order_list[self._position]
        return self._collection[result]

    def has_next(self) -> bool:
        if not self._reverse:
            return self._position < len(self._order_list)
        return self.position >= 0

    def has_previous(self) -> bool:
        if not self._reverse:
            return self._position > 0
        return self._position < len(self._order_list) - 1
