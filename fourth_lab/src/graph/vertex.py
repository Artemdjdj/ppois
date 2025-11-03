from typing import TypeVar, Generic, Hashable

T = TypeVar('T', bound=Hashable)


class Vertex(Generic[T]):
    _next_id:int = 0
    def __init__(self, data: T):
        self._data: int = data
        self._id:int =  Vertex._next_id
        Vertex._next_id += 1

    @property
    def data(self) -> T:
        return self._data

    @data.setter
    def data(self, data: T):
        self._data = data

    @property
    def id(self):
        return self._id

    def __hash__(self):
        return hash(self.id)

    def __eq__(self, other):
        if not isinstance(other, Vertex):
            raise TypeError("You cannot compare a Vertex with a different type")
        return self._id == other.id

    def __repr__(self):
        return f"ID: {self._id} with data: {self.data}"
