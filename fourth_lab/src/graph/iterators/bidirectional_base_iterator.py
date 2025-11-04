from typing import Generic, TypeVar, Self
from abc import ABC, abstractmethod
from src.graph.vertex import Vertex

T = TypeVar('T')


class IBidirectionalBaseIterator(ABC, Generic[T]):
    @abstractmethod
    def __iter__(self) -> Self:
        pass

    @abstractmethod
    def __next__(self) -> T:
        pass

    @abstractmethod
    def previous(self) -> T:
        pass

    @abstractmethod
    def has_next(self) -> bool:
        pass

    @abstractmethod
    def has_previous(self) -> bool:
        pass
