from typing import Generic, TypeVar
from abc import ABC, abstractmethod
from src.graph.vertex import Vertex

T = TypeVar('T')

class IBidirectionalBaseIterator(ABC, Generic[T]):
    @abstractmethod
    def __iter__(self):
        pass

    @abstractmethod
    def __next__(self)->Vertex[T]:
        pass

    @abstractmethod
    def previous(self):
        pass

    @abstractmethod
    def has_next(self) -> bool:
        pass

    @abstractmethod
    def has_previous(self) -> bool:
        pass

