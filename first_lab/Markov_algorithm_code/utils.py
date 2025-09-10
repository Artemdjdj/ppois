"""
Этот модуль выполняет второстепенную задачу, в нем описана вспомогательная функция бинарного поиска
"""
from typing import List

def binary_search(arr_of_chars:List[str], some_char:str)->bool:
    """Эта функция ищет символ в строке

    Args:
        arr_of_chars (List[str])
        some_char (str)

    Returns:
        bool
    """
    left = 0
    right = len(arr_of_chars) - 1
    while left<=right:
        mid = (left+right)//2
        if arr_of_chars[mid] == some_char:
            return True
        elif arr_of_chars[mid] > some_char:
            right = mid - 1
        else:
            left = mid + 1
    return False

