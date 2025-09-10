"""
В этом модуле описан класс правила. Сам класс состоит из множества атрибутов и методов, которые и определяют
структуру класса
"""

class Rule:
    """Этот класс описывает правила которые будет выполнять машина Тьюринга"""
    def __init__(self, current_rule_name, current_value, next_rule_name, next_value, direction):
        """Эта функция инициализирует правила"""
        self.__current_rule_name =current_rule_name
        self.__current_value = current_value
        self.__next_rule_name = next_rule_name
        self.__next_value = next_value
        self.__direction = direction

    def __str__(self):
        """Эта функция выводит соответствующее правило"""
        return (f"Текущее правило: {self.__current_rule_name} текущее значение: {self.__current_value}     ----> \
        Следующее правило: {self.__next_rule_name}  новое значение: {self.__next_value}  направление:\
        {self.__direction}")

    def __eq__(self, some_rule):
        """Эта функция проверяет идентичность правил"""
        if not isinstance(some_rule, Rule):
            return False
        return self.__current_rule_name == some_rule.__current_rule_name and \
            self.__current_value == some_rule.__current_value and \
            self.__next_rule_name == some_rule.__next_rule_name and \
            self.__next_value == some_rule.__next_value and \
            self.__direction == some_rule.__direction

    def get_current_rule_name(self):
        """ Возвращает текущее название правила"""
        return self.__current_rule_name

    def get_current_value(self):
        """ Возвращает значение для правила"""
        return self.__current_value

    def get_next_rule_name(self):
        """ Возвращает  следующее имя правила"""
        return self.__next_rule_name

    def get_next_value(self):
        """ Возвращает значение для следующего правила"""
        return self.__next_value

    def get_direction(self):
        """ Возвращает направление движения"""
        return self.__direction


# rule = Rule("q0", 1,"q2", 2, "right")
# print(rule.__str__())