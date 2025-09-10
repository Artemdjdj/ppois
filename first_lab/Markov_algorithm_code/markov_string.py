"""
В этом модуле описан класс строки Маркова
"""

class MarkovString:
    """Этот класс описывает строку алгорифма маркова"""

    def __init__(self, string:str)->None:
        """Эта функция инициализирует строку

        Args:
            string (str)
        """
        self.__markov_string = string

    def replacing_one_string_with_another(self, search_string:str, replace_string:str, stop_symbol:str)->bool:
        """Эта функция заменяет одну подстроку на другую, если первая существует в строке

        Args:
            search_string (str)
            replace_string (str)
            stop_symbol (str)

        Returns:
            bool
        """
        start_index = self.__markov_string.find(search_string)
        if start_index == -1:
            return False
        len_search_string = len(search_string)
        if len(replace_string)>0 and  replace_string[-1] == stop_symbol:
            replace_string = replace_string[:-1]
        new_string = self.__markov_string[0:start_index]+replace_string+self.__markov_string[start_index+\
            len_search_string:]
        self.__markov_string = new_string
        return True

    def set_string_value(self, string_input:str)->None:
        """Эта функция присваивает новое значение строке

        Args:
            string_input (str)
        """
        self.__markov_string = string_input

    def __str__(self)->str:
        """Эта функция выводит получившуюся строку

        Returns:
            str
        """
        return self.__markov_string


