"""Файл vertex.py необходим для определения класса вершины графа."""
from typing import TypeVar, Generic, Hashable

T = TypeVar('T', bound=Hashable)


class Vertex(Generic[T]):
    """Представляет вершину в графе.

    Вершина содержит данные (любого хешируемого типа) и уникальный
    идентификатор. Каждой вершине автоматически присваивается ID при создании.
    Вершины могут использоваться как ключи в словарях и элементы множеств
    благодаря методам __hash__ и __eq__.

    Args:
        T: Тип данных вершины, должен быть хешируемым.

    Attributes:
        data (T): Данные, хранящиеся в вершине.
        id (int): Уникальный идентификатор вершины.
    """

    _next_id: int = 0

    def __init__(self, data: T):
        """Инициализирует новую вершину.

        Args:
            data (T): Данные для сохранения в вершине.
        """
        self._data: T = data
        self._id: int = Vertex._next_id
        Vertex._next_id += 1

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

    def __hash__(self) -> int:
        """Возвращает хеш вершины на основе её ID.

        Returns:
            int: Хеш вершины.
        """
        return hash(self.id)

    def __eq__(self, other) -> bool:
        """Проверяет равенство двух вершин.

        Две вершины считаются равными, если имеют одинаковый ID.

        Args:
            other (Vertex): Другая вершина для сравнения.

        Returns:
            bool: True, если вершины имеют одинаковый ID, иначе False.

        Raises:
            TypeError: Если other не является экземпляром Vertex.
        """
        if not isinstance(other, Vertex):
            raise TypeError("You cannot compare a Vertex with a different type")
        return self._id == other.id

    def __repr__(self) -> str:
        """Возвращает строковое представление вершины.

        Returns:
            str: Строка с информацией об ID и данных вершины.
        """
        return f"ID: {self._id} with data: {self.data}"
