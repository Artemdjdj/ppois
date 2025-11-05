"""Файл utils.py необходим для определения класса работы со списками и классов валидации."""

from abc import abstractclassmethod, abstractmethod, ABC
from typing import TypeVar, List, Generic, Optional, Callable, Union

T = TypeVar('T')


class ValuesOfArray:
    """Класс ValuesOfArray работает со списками с разными типами данных для получения определенных значений."""

    @staticmethod
    def get_value(is_max: bool, array: List[T], key: Optional[Callable[[T], Union[int, float]]] = None) -> Union[
        int, float]:
        """ Функция ищет минимум или максимум исходного списка.

        Функция принимает списки любых типов данных, однако для поиска максимума или минимума нужны списки типа int
        или float, либо списки пользовательского типа данных, то есть элементом списка является класс, однако если список
        состоит из элементов пользовательского типа данных, то обязательно у него должны быть поля типа int или float.

        Args:
            is_max (bool): Флаг (True - максимальный, False - Минимальный).
            array (List[T]): Исходный список.
            key (Optional[Callable[[T], Union[int, float]]]): Функция преобразования.

        Returns:
            Union[int, float]: Числовой результат.

        Raises:
            Exception:
            Если пустой список;
            если функция преобразования отсутствует и список состоит не из числовых данных;
            если функция преобразования не возвращает числовой результат.
        """
        if not array:
            raise Exception('Array is empty')
        if key is None:
            if not NumberValidator().is_valid(array[0]):
                raise Exception('Elements must be of type int or float when key is None')
            if is_max:
                return max(array)
            return min(array)
        res_value = key(array[0])
        if not NumberValidator().is_valid(res_value):
            raise Exception(f'Key function must return a number')
        for i in range(1, len(array)):
            value = key(array[i])
            if not NumberValidator().is_valid(value):
                raise Exception(f'Key function must return a number')
            if is_max and value > res_value:
                res_value = value
            elif not is_max and value < res_value:
                res_value = value
        return res_value


class Validator(ABC, Generic[T]):
    """Абстрактный класс для валидирования данных."""

    @abstractmethod
    def is_valid(self, check_element: T) -> bool:
        """Функция проверяет валидность данных.

        Args:
            check_element (T): Проверяемый элемент.

        Returns:
            True если элемент валидный, False -  в противном случае.
        """
        pass


class NumberValidator(Validator[Union[int, float]]):
    """Класс валидации чисел."""

    def is_valid(self, check_element: Union[int, float]) -> bool:
        """Функция проверяет, что переданное значение в качестве аргумента является числовым типом данных.

        Args:
            check_element (Union[int, float]): Проверяемое значение.

        Returns:
            True если значение числовое, False - в противном случае.
        """
        return isinstance(check_element, (int, float))

class IntValidator(Validator[int]):
    """Класс валидации целых чисел."""

    def is_valid(self, check_element: int) -> bool:
        """Функция проверяет, что переданное значение в качестве аргумента является типом данных int.

        Args:
            check_element (int): Проверяемое значение.

        Returns:
            True если значение целое, False - в противном случае.
        """
        return isinstance(check_element, int)