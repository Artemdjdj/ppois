"""Файл bidirectional_vertex_and_edge_iterator.py для определения логики итератора по вершинам или ребрам."""

from src.graph.exceptions.exceptions import IncorrectPosition
from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from src.graph.vertex import Vertex
from src.graph.edge import Edge
from typing import TypeVar, List, Self, Union, Dict, Generic

T = TypeVar('T')


class BidirectionalVertexAndEdgeIterator(IBidirectionalBaseIterator, Generic[T]):
    """
    Двусторонний итератор для обхода вершин или рёбер графа.

    Этот универсальный итератор может работать с коллекцией вершин
    (Dict[int, Vertex[T]]) или коллекцией рёбер (Dict[int, Edge]).

    Attributes:
        _collection (Union[Dict[int, Vertex[T]], Dict[int, Edge]]): Коллекция элементов.
        _order_list (List[int]): Список ID элементов в порядке обхода.
        _position (int): Текущий индекс позиции в order_list.
        _reverse (bool): Флаг обратного направления обхода.
    """
    __slots__ = ('_collection', '_order_list', '_position', '_reverse')

    def __init__(self, collection: Union[Dict[int, Vertex[T]], Dict[int, Edge]], order_list: List[int],
                 reverse: bool = False) -> None:
        """
        Инициализирует итератор по вершинам или рёбрам.

        Args:
            collection (Union[Dict[int, Vertex[T]], Dict[int, Edge]]): Словарь вершин или рёбер.
            order_list (List[int]): Упорядоченный список ID вершин или рёбер.
            reverse (bool, optional): Если True, начинать с конца, изначально False.
        """
        self._collection = collection
        self._order_list = order_list
        self._position = 0 if not reverse else len(collection) - 1
        self._reverse = reverse

    @property
    def position(self) -> int:
        """
        Возвращает текущую позицию в order_list.

        Returns:
            int: Индекс текущей позиции.
        """
        return self._position

    @position.setter
    def position(self, position: int) -> None:
        """
        Устанавливает новую позицию в order_list.

        Args:
            position (int): Новый индекс позиции.
        """
        self._position = position

    def current_element(self) -> int:
        """
        Возвращает ID текущего элемента из order_list.

        Метод проверяет, что текущая позиция находится в допустимых границах.

        Returns:
            int: ID вершины или ребра, на которое указывает текущая позиция.

        Raises:
            IncorrectPosition: Если позиция выходит за границы [0, len(order_list)).
        """
        if self._position < 0 or self._position >= len(self._order_list):
            raise IncorrectPosition("Iterator out of bounds")
        return self._order_list[self._position]

    def __set_position(self, value: int) -> None:
        """
        Внутренний метод для изменения _position.

        Args:
            value (int): Новое значение позиции.
        """
        object.__setattr__(self, '_position', value)

    def __iter__(self) -> Self:
        """
        Возвращает сам итератор.

        Returns:
            Self: Этот же итератор.
        """
        return self

    def __next__(self) -> Union[Vertex[T], Edge]:
        """
        Возвращает следующий элемент (вершину или ребро) и переходит вперёд.

        Returns:
            Union[Vertex[T], Edge]: Следующая вершина или ребро.

        Raises:
            StopIteration: Когда больше нет элементов для итерации.
        """
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
        """
        Возвращает предыдущий элемент (вершину или ребро) и переходит назад.

        Returns:
            Union[Vertex[T], Edge]: Предыдущая вершина или ребро.

        Raises:
            StopIteration: Когда нет предыдущих элементов.
        """
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
        """
        Проверяет наличие следующего элемента.

        Returns:
            bool: True, если есть следующий элемент, False — нет.
        """
        if not self._reverse:
            return self._position < len(self._order_list)
        return self.position >= 0

    def has_previous(self) -> bool:
        """
        Проверяет наличие предыдущего элемента.

        Returns:
            bool: True, если есть предыдущий элемент, False — нет.
        """
        if not self._reverse:
            return self._position > 0
        return self._position < len(self._order_list) - 1
