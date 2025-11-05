"""Файл vertex.py необходим для определения класса вершины графа."""

from typing import TypeVar, Generic, Hashable

T = TypeVar('T', bound=Hashable)


class Vertex(Generic[T]):
    """Представляет вершину в графе.

    Вершина содержит данные (любого хешируемого типа) и уникальный
    идентификатор. Каждой вершине автоматически присваивается ID при создании.

    Args:
        T: Тип данных вершины, должен быть хешируемым.

    Attributes:
        data (T): Данные, хранящиеся в вершине.
        id (int): Уникальный идентификатор вершины.
    """

    def __init__(self, data: T):
        """Инициализирует новую вершину.

        Args:
            data (T): Данные для сохранения в вершине.
        """
        self._data: T = data
        self._id = None

    @property
    def data(self) -> T:
        """T: Данные, хранящиеся в вершине."""
        return self._data

    @data.setter
    def data(self, data: T) -> None:
        """Устанавливает новые данные для вершины.

        Args:
            data (T): Новые данные для вершины.
        """
        self._data = data

    @property
    def id(self) -> int:
        """int: Уникальный идентификатор вершины."""
        return self._id

    @id.setter
    def id(self, value:int) -> None:
        """None: Установка уникального идентификатора вершины."""
        self._id = value

    def __eq__(self, other) -> bool:
        """Проверяет равенство двух вершин.

        Две вершины считаются равными, если имеют одинаковые данные.

        Args:
            other (Vertex): Другая вершина для сравнения.

        Returns:
            bool: True, если вершины имеют одинаковые данные, иначе False.

        Raises:
            TypeError: Если other не является экземпляром Vertex.
        """
        if not isinstance(other, Vertex):
            raise TypeError("You cannot compare a Vertex with a different type")
        return self._data == other.data

    def __repr__(self) -> str:
        """Возвращает строковое представление вершины.

        Returns:
            str: Строка с информацией об ID и данных вершины.
        """
        return f"ID: {self._id} with data: {self._data}"

    def __str__(self) -> str:
        """Возвращает строковое представление вершины.

        Returns:
            str: Строка с информацией о вершине
        """
        return f"{self._data}"
