from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from typing import TypeVar, List, Self
from src.graph.vertex import Vertex

T = TypeVar('T')

class VertexBidirectionalIterator(IBidirectionalBaseIterator):
    def __init__(self, collection:List[Vertex[T]], position:int = 0)->None:
        self._collection = collection
        self.position = position if position >=0 else 0

    @property
    def position(self) -> int:
        return self.position

    def __iter__(self)->Self:
        return self

    def __next__(self)->Vertex[T]:
        if not self.has_next():
            raise StopIteration
        vertex = self._collection[self.position]
        self.position += 1
        return vertex

    def previous(self)->Vertex[T]:
        if not self.has_previous():
            raise StopIteration
        vertex  = self._collection[self.position]
        self.position -= 1
        return vertex

    def has_next(self) -> bool:
        return self.position < len(self._collection)

    def has_previous(self):
        return self.position >= 0


