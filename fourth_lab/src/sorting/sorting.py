"""Файл sorting.py необходим для определения классов сортировок."""

from abc import ABC, abstractmethod
from typing import TypeVar, Optional, Callable, Generic, List, Any
from src.sorting.utils import ValuesOfArray, IntValidator

T = TypeVar('T')


class Sorting(ABC, Generic[T]):
    """Абстрактный класс для сортировок."""

    @abstractmethod
    def sort(self, array: List[T],
             key: Optional[Callable[[T], Any]] = None) -> List[T]:
        """Функция проверяет валидность данных.

            Args:
                array (List[T]): Список элементов.
                key (Optional[Callable[[T], Any]]): Функция преобразования,  default = None.
            Returns:
                List[T]: Отсортированный список.
        """
        pass


class GnomeSorting(Sorting[T]):
    """Класс сортировки "гномом", Gnome Sort"""

    def sort(self, array: List[T],
             key: Optional[Callable[[T], Any]] = None, reverse=False) -> List[T]:
        """Функция сортирует список, используя алгоритм сортировки Gnome Sort.

            Args:
                array (List[T]): Список элементов.
                key (Optional[Callable[[T], Any]]): Функция преобразования,  default = None.
                reverse (bool): Флаг (Сортировка в обратном порядке).
            Returns:
                List[T]: Отсортированный список.
        """
        index = 0
        length = len(array)
        while index < length:
            value = key(array[index]) if key else array[index]
            prev_value = key(array[index - 1]) if key else array[index - 1]
            comparison_result = value>=prev_value if not reverse else value<=prev_value
            if index == 0 or comparison_result:
                index += 1
            else:
                array[index], array[index - 1] = array[index - 1], array[index]
                index -= 1


        return array


class PigeonholeSorting(Sorting):
    """Класс сортировки методом "голубиного ящика", Pigeonhole Sort"""

    def sort(self, array: List[T], key: Optional[Callable[[T], int]] = None, reverse=False) -> List[T]:
        """Функция сортирует список, используя алгоритм сортировки Pigeonhole Sort.

            Args:
                array (List[T]): Список элементов.
                key (Optional[Callable[[T], int]]): Функция преобразования,  default = None.
                reverse (bool): Флаг (Сортировка в обратном порядке).
            Returns:
                List[T]: Отсортированный список.
            Raises:
                TypeError: Если рамер промежуточного массива не int.
        """
        max_value = ValuesOfArray.get_value(True, array, key)
        min_value = ValuesOfArray.get_value(False, array, key)
        size = max_value - min_value + 1
        if not IntValidator().is_valid(size):
            raise TypeError("Incorrect type of arr")
        temp_array = [[] for _ in range(size)]
        for element in array:
            temp_i = key(element) if key else element
            index = temp_i - min_value
            temp_array[index].append(element)
        result_array = []
        result_temp_array = temp_array if not reverse else reversed(temp_array)
        for temp_element in result_temp_array:
            result_array.extend(temp_element)
        return result_array
