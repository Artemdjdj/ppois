from abc import abstractclassmethod, abstractmethod, ABC
from typing import TypeVar, List, Generic, Optional, Callable, Union

T = TypeVar('T')


class ValuesOfArray:
    @staticmethod
    def get_maximum(array: List[T], key: Optional[Callable[[T], Union[int, float]]] = None) ->Union[int, float] :
        if not array:
            raise Exception('Array is empty')
        if key is None:
            if not isinstance(array[0], (int, float)):
                raise Exception('Elements must be of type int or float when key is None')
            return max(array)
        max_value = key(array[0])
        if not isinstance(max_value, (int, float)):
            raise Exception(f'Key function must return a number')
        for i in range(1, len(array)):
            value = key(array[i])
            if not isinstance(value, (int, float)):
                raise Exception(f'Key function must return a number')
            if value > max_value:
                max_value = value
        return max_value

    @staticmethod
    def get_minimum(array: List[T], key: Optional[Callable[[T], Union[int, float]]] = None) ->Union[int, float] :
        if not array:
            raise Exception('Array is empty')
        if key is None:
            if not isinstance(array[0], (int, float)):
                raise Exception('Elements must be of type int or float when key is None')
            return min(array)
        min_value = key(array[0])
        for i in range(1, len(array)):
            value = key(array[i])
            if value < min_value:
                min_value = value
        return min_value


class Validator(ABC, Generic[T]):
    @abstractmethod
    def is_valid(self, check_element: T) -> bool:
        pass


class NumberValidator(Validator[Union[int, float]]):
    def is_valid(self, check_element: Union[int, float]) -> bool:
        return isinstance(check_element, (int, float))
