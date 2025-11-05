"""Файл bidirectional_base_iterator.py для определения базовой логики любого итератора."""

from typing import Generic, TypeVar, Self
from abc import ABC, abstractmethod

T = TypeVar('T')


class IBidirectionalBaseIterator(ABC, Generic[T]):
    """
    Абстрактный базовый класс для двусторонних итераторов.

    Определяет интерфейс, который должны реализовать все двусторонние
    итераторы. Двусторонний итератор позволяет перемещаться как вперёд
    (через __next__), так и назад (через previous), а также проверять
    возможность движения в обе стороны.
    """

    @abstractmethod
    def __iter__(self) -> Self:
        """
        Возвращает итератор.

        Returns:
            Self: Этот же итератор.
        """
        pass

    @abstractmethod
    def __next__(self) -> T:
        """
        Возвращает следующий элемент и переходит на одну позицию вперёд.

        Returns:
            T: Следующий элемент типа T.

        Raises:
            StopIteration: Когда нет больше элементов для итерации.
        """
        pass

    @abstractmethod
    def previous(self) -> T:
        """
        Возвращает предыдущий элемент и переходит на одну позицию назад.

        Returns:
            T: Предыдущий элемент типа T.

        Raises:
            StopIteration: Когда нет предыдущих элементов.
        """
        pass

    @abstractmethod
    def has_next(self) -> bool:
        """
        Проверяет, есть ли следующий элемент.

        Returns:
            bool: True, если есть следующий элемент, False — нет.
        """
        pass

    @abstractmethod
    def has_previous(self) -> bool:
        """
        Проверяет, есть ли предыдущий элемент.

        Returns:
            bool: True, если есть предыдущий элемент, False — нет.
        """
        pass
