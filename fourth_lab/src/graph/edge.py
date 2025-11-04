"""Файл edge.py необходим для определения класса ребра графа."""
from typing import TypeVar, Generic, Hashable


class Edge:
    """Представляет направленное ребро в графе.

    Ребро соединяет две вершины, идентифицируемые их индексами. Каждому
    ребру автоматически присваивается уникальный идентификатор. Рёбра
    сравниваются на основе исходной и целевой вершины.

    Attributes:
        v_from (int): Индекс исходной вершины.
        v_to (int): Индекс целевой вершины.
        id (int): Уникальный идентификатор, присвоенный ребру при создании.
    """

    _next_id: int = 0

    def __init__(self, v_from: int, v_to: int):
        """Инициализирует новое ребро.

        Args:
            v_from (int): Индекс исходной (начальной) вершины.
            v_to (int): Индекс целевой (конечной) вершины.
        """
        self._v_from: int = v_from
        self._v_to: int = v_to
        self._id = Edge._next_id
        Edge._next_id += 1

    @property
    def v_from(self) -> int:
        """int: Индекс исходной вершины."""
        return self._v_from

    @property
    def v_to(self) -> int:
        """int: Индекс целевой вершины."""
        return self._v_to

    @property
    def id(self) -> int:
        """int: Уникальный идентификатор ребра."""
        return self._id

    def __eq__(self, other) -> bool:
        """Проверяет равенство двух рёбер.

        Два ребра считаются равными, если имеют одинаковые исходную
        и целевую вершины.

        Args:
            other (Edge): Другое ребро для сравнения.

        Returns:
            bool: True, если рёбра имеют одинаковые v_from и v_to, иначе False.

        Raises:
            TypeError: Если other не является экземпляром Edge.
        """
        if not isinstance(other, Edge):
            raise TypeError("You can't compare an Edge with a different type")
        return self._v_from == other.v_from and self._v_to == other.v_to

    def __repr__(self) -> str:
        """Возвращает строковое представление ребра.

        Returns:
            str: Читаемое представление с указанием исходной и целевой вершины.
        """
        return f"Edge (from: {self.v_from}, to: {self.v_to})"
