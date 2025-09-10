"""
В этом модуле описан класс правила. Сам класс состоит из множества атрибутов и методов, которые и определяют
структуру класса
"""

class Rule:
    """Этот класс описывает правила которые будет выполнять машина Тьюринга"""
    def __init__(self, current_rule_name:str, current_value:str, next_rule_name:str, next_value:str, direction:str)->None:
        """Эта функция инициализирует правила

        Args:
            current_rule_name (str)
            current_value (str)
            next_rule_name (str)
            next_value (str)
            direction (str)
        """
        self.__current_rule_name =current_rule_name
        self.__current_value = current_value
        self.__next_rule_name = next_rule_name
        self.__next_value = next_value
        self.__direction = direction

    def __str__(self)->str:
        """Эта функция выводит соответствующее правило

        Returns:
            str
        """
        return (f"Текущее правило: {self.__current_rule_name} текущее значение: {self.__current_value}     ----> \
        Следующее правило: {self.__next_rule_name}  новое значение: {self.__next_value}  направление:\
        {self.__direction}")

    def __eq__(self, some_rule)->bool:
        """Эта функция проверяет идентичность правил

        Args:
            some_rule (Rule)

        Returns:
            bool
        """
        if not isinstance(some_rule, Rule):
            return False
        return self.__current_rule_name == some_rule.__current_rule_name and \
            self.__current_value == some_rule.__current_value and \
            self.__next_rule_name == some_rule.__next_rule_name and \
            self.__next_value == some_rule.__next_value and \
            self.__direction == some_rule.__direction

    def get_current_rule_name(self)->str:
        """Возвращает текущее название правила

        Returns:
            str
        """
        return self.__current_rule_name

    def get_current_value(self)->str:
        """Возвращает значение для правила

        Returns:
            str
        """
        return self.__current_value

    def get_next_rule_name(self)->str:
        """Возвращает  следующее имя правила

        Returns:
            str
        """
        return self.__next_rule_name

    def get_next_value(self)->str:
        """Возвращает значение для следующего правила

        Returns:
            str
        """
        return self.__next_value

    def get_direction(self)->str:
        """Возвращает направление движения

        Returns:
            str
        """
        return self.__direction