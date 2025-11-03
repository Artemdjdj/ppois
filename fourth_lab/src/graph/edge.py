
from typing import TypeVar, Generic, Hashable

class Edge:
    _next_id:int = 0
    def __init__(self, v_from:int, v_to:int):
        self._v_from:int = v_from
        self._v_to:int = v_to
        self._id = Edge._next_id
        Edge._next_id += 1

    @property
    def v_from(self):
        return self._v_from

    @property
    def v_to(self):
        return self._v_to

    @property
    def id(self):
        return self._id

    def __eq__(self, other):
        if not isinstance(other, Edge):
            raise TypeError("You can't compare an Edge with a different type")
        return self._v_from == other.v_from and self._v_to == other.v_to

    def __repr__(self):
        return f"Edge (from: {self.v_from}, to: {self.v_to})"

