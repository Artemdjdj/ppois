"""
В этом модуле описан класс правила. Он необходим для хранения и обработки правил, он задает им определенный стиль
"""

class Rule:
    """Этот класс описывает правило"""
    def __init__(self, search_string:str, replace_string:str)->None:
        """Эта функция описывает инициализацию правила

        Args:
            search_string (str)
            replace_string (str)
        """
        self.__search_string = search_string
        self.__replace_string = replace_string

    def get_search_string(self)->str:
        """Эта функция возвращает строку, которую нужно заменить

        Returns:
            str
        """
        return self.__search_string

    def get_replace_string(self)->str:
        """Эта функция возвращает строку, которая заменяет предыдущую строку

        Returns:
            str
        """
        return self.__replace_string

    def __eq__(self, some_rule)->bool:
        """Эта функция проверяет идентичность правил

        Args:
            some_rule (Rule)

        Returns:
            bool: 
        """
        if not isinstance(some_rule, Rule):
            return False
        return self.__search_string == some_rule.__search_string and self.__replace_string ==some_rule.__replace_string

    def __str__(self)->str:
        """Эта функция выводит правила в красивом виде

        Returns:
            str
        """
        return f" Искомая подстрока: {self.__search_string}  ---> Новая подстрока: {self.__replace_string}"
