"""
Этот модуль описывает класс ленты. Сам класс состоит из двух аргументов и небольшого количества различных функций
"""

from Turing_machine_code.settings import dict_of_settings

class Tape:
    """Этот класс описывает ленту машины Тьюринга"""
    def __init__(self, string:str)->None:
        """Эта функция инициализирует ленту

        Args:
            string (str)
        """
        self.__len_of_tape = dict_of_settings.get('len_of_tape', 0)
        self.__tape = [dict_of_settings.get('default_symbol', '-')]*self.__len_of_tape+list(map(str, string))+\
                      [dict_of_settings.get('default_symbol', '-')]*self.__len_of_tape

    def get_symbol_from_tape(self, position_of_carriage:int)->str|None:
        """Эта функция получает символ по позиции

        Args:
            position_of_carriage (int)

        Returns:
            str|None
        """
        try:
            return self.__tape[position_of_carriage]
        except IndexError:
            # print("\n Problem with getting symbol!")
            return None

    def get_tape(self)->str:
        """Эта функция возвращает ленту

        Returns:
            str
        """
        return self.__tape

    def set_symbol_in_tape(self, position_of_carriage:int, new_symbol:str)->None:
        """Эта функция заменят текущий символ на этой позиции на новый

        Args:
            position_of_carriage (int)
            new_symbol (str)
        """
        try:
            self.__tape[position_of_carriage] = new_symbol
        except IndexError:
            print("\n Problem with setting symbol!")

