"""@package docstring
Этот модуль является вспомогательным, в нем проверяется соответствие символов определенному алфавиту
"""

from Turing_machine_code.settings import dict_of_settings, get_settings
from Markov_algorithm_code.utils import binary_search
# def binary_search(arr_of_chars, some_char):
#     """Эта функция ищет символ в строке"""
#     left = 0
#     right = len(arr_of_chars) - 1
#     while left<=right:
#         mid = (left+right)//2
#         if arr_of_chars[mid] == some_char:
#             return True
#         elif arr_of_chars[mid] > some_char:
#             right = mid - 1
#         else:
#             left = mid + 1
#     return False

def check_input_rule(list_of_keys:list)->bool:
    """Эта функция проверяет правило поступившее на вход"""
    # print(list_of_keys)
    current_value = str(list_of_keys[2])
    next_value = str(list_of_keys[4])
    get_settings()
    letters = sorted(list(dict_of_settings['alphabet']))
    for letter in current_value:
        if not binary_search(letters, letter):
            return False
    for letter in next_value:
        if not binary_search(letters, letter):
            return False
    return True

def check_input_value(value):
    """Эта функция проверяет что значение подходит алфавиту"""
    letters = sorted(list(dict_of_settings['alphabet']))
    for letter in value:
        if not binary_search(letters, letter):
            return False
    return True