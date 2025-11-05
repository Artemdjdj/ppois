"""Файл utils.py необходим для определения утилитарного класса."""

from typing import List


class Counter:
    """Утилитарный класс для подсчёта элементов в списках.

    Предоставляет статические методы для подсчёта количества вхождений
    элемента и поиска его позиций в списке.
    """

    @staticmethod
    def count_number_in_list(arr: List[int], number: int) -> int:
        """Подсчитывает количество вхождений числа в список.

        Args:
            arr (List[int]): Список для поиска.
            number (int): Число, количество вхождений которого нужно подсчитать.

        Returns:
            int: Общее количество вхождений числа в список.
        """
        count = 0
        for el in arr:
            if el == number:
                count += 1
        return count

    @staticmethod
    def count_elements_in_list(arr: List[int], element: int) -> List[int]:
        """Находит все индексы вхождения элемента в список.

        Args:
            arr (List[int]): Список для поиска.
            element (int): Элемент, индексы которого нужно найти.

        Returns:
            List[int]: Список индексов, где найден элемент в массиве.
        """
        res_arr = []
        for i, el in enumerate(arr):
            if el == element:
                res_arr.append(i)
        return res_arr
