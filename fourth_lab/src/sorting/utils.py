from abc import abstractclassmethod, abstractmethod, ABC
from typing import TypeVar, List, Generic, Optional, Callable, Union

T = TypeVar('T')


class ValuesOfArray:
    @staticmethod
    def get_value(is_max: bool, array: List[T], key: Optional[Callable[[T], Union[int, float]]] = None) -> Union[
        int, float]:
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
    @abstractmethod
    def is_valid(self, check_element: T) -> bool:
        pass


class NumberValidator(Validator[Union[int, float]]):
    def is_valid(self, check_element: Union[int, float]) -> bool:
        return isinstance(check_element, (int, float))
