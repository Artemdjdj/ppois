from settings import dict_of_settings
from rule import Rule
from tape import Tape


class TuringMachine:
    """Этот класс является главным, в нем реализована каретка, а также сам механизм машины Тьюринга """
    def __init__(self, carriage,string, start_state, start_value):
        self.__carriage = carriage
        self.__tape = Tape(string)
        self.__rules= {}
        self.__current_state = start_state
        self.__current_value = start_value

    def __str__(self):
        """Эта функция делает отчет о состоянии машины Тьюринга"""
        return (f"На данный момент:\
        каретка находится на позиции: {self.__carriage} \
        текущая операция: {self.__current_state} \
        текущее значение: {self.__current_value}")

    def get_tape_to_turing_machine(self):
        """Эта функция возвращает ленту"""
        return self.__tape.get_tape()

    def extend_rules(self, tuple_rule, rule):
        """Эта функция добавляет правило в словарь правил для машины Тьюринга"""
        self.__rules[tuple_rule] = rule

    def move_carriage_and_make_some_action(self, is_start):
        """Эта функция будет выполнять какое-то действие по правилу, либо, если правило не
         будет найдено, или действие будет последним, функция вернет значение False, иначе True"""
        if is_start:
            self.__current_state = "qstart"
            self.__current_value = self.__tape.get_tape()[self.__carriage]
            return True
        rule = self.__rules.get((self.__current_state, self.__current_value), None)
        if not rule:
            return False
        self.__current_state = rule.get_next_rule_name()
        self.__tape.set_symbol_in_tape(self.__carriage, rule.get_next_value())
        left_of_right_direction = 1 if rule.get_direction() == 'right' else -1
        self.__carriage += left_of_right_direction
        self.__current_value = self.__tape.get_tape()[self.__carriage]
        if self.__current_state =="qfinish":
            return False
        return True






