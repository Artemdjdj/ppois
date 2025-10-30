from abc import ABC, abstractmethod
from typing import TypeVar,Optional, Callable, Generic, List, Any
from src.sorting.utils import ValuesOfArray

T = TypeVar('T')

class Sorting(ABC, Generic[T]):
    @abstractmethod
    def sort(self, array: List[T],
        key: Optional[Callable[[T], Any]] = None) -> List[T]:
        pass

class GnomeSorting(Sorting[T]):
    def sort(self, array:List[T],
        key:Optional[Callable[[T], Any]] = None) -> List[T]:
        index = 0
        length = len(array)
        while index < length:
            value = key(array[index]) if key else array[index]
            prev_value = key(array[index - 1]) if key else array[index - 1]
            if index == 0 or value >= prev_value:
                index += 1
            else:
                array[index], array[index - 1] = array[index - 1], array[index]
                index -= 1
        return array

class PigeonholeSorting(Sorting):
    def sort(self, array: List[T],key:Optional[Callable[[T], int]] = None) -> List[T]:
        max_value = ValuesOfArray.get_maximum(array, key)
        min_value = ValuesOfArray.get_minimum(array, key)
        size = max_value - min_value + 1
        if not isinstance(size, int):
            raise TypeError("Incorrect type of arr")
        temp_array = [[] for _ in range(size)]
        for element in array:
            temp_i = key(element) if key else element
            index = temp_i - min_value
            temp_array[index].append(element)
        result_array = []
        for temp_element in temp_array:
            result_array.extend(temp_element)
        return result_array








