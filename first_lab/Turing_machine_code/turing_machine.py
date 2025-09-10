"""
Этот модуль описывает класс машины Тьюринга, в нем реализована вся необходимая логика.
Один из важнейших файлов!
"""
from Turing_machine_code.settings import dict_of_settings
from Turing_machine_code.rule import Rule
from Turing_machine_code.tape import Tape
from Turing_machine_code.utils import check_input_value
from typing import List, Tuple, Callable


class TuringMachine:
    """Этот класс является главным, в нем реализована каретка, а также сам механизм машины Тьюринга """
    def __init__(self, carriage:int, start_state:str, start_value:str, tape:Tape=Tape(""))->None:
        """Этафункция инициализирует экземпляр класса машины Тьюринга

        Args:
            carriage (int)
            start_state (str)
            start_value (str)
            tape (Tape, optional). Defaults to Tape("").
        """
        self.__carriage = carriage
        self.__tape = tape
        self.__rules= {}
        self.__current_state = start_state
        self.__current_value = start_value

    def __str__(self)->str:
        """Эта функция делает отчет о состоянии машины Тьюринга

        Returns:
            str
        """
        return (f"На данный момент:\
        каретка находится на позиции: {self.__carriage} \
        текущая операция: {self.__current_state} \
        текущее значение: {self.__current_value}")

    def get_tape_to_turing_machine(self)->str:
        """Эта функция возвращает ленту

        Returns:
            str
        """
        return self.__tape.get_tape()

    def get_tape_from_turing_machine(self)->Tape:
        """Эта функция возвращает ленту (как обьект)

        Returns:
            Tape
        """
        return self.__tape

    def extend_rules(self, tuple_rule:Tuple[Callable, Callable], rule:Rule)->None:
        """Эта функция добавляет правило в словарь правил для машины Тьюринга

        Args:
            tuple_rule (Tuple[Callable, Callable])
            rule (Rule)
        """
        self.__rules[tuple_rule] = rule

    def extend_rules_using_list_of_keys(self, res_arr_of_rules:List[List[Tuple[Callable, Callable]|Rule]])->bool:
        """Эта функция добавляет правила, используя весь готовый набор правил

        Args:
            res_arr_of_rules (List[List[Tuple[Callable, Callable] | Rule]])

        Returns:
            bool
        """
        is_qstart = False
        for el in res_arr_of_rules:
            tuple_rule = el[0]
            rule = el[1]
            if not is_qstart and rule.get_current_rule_name()=="qstart":
                is_qstart = True
            self.__rules[tuple_rule] = rule
        if not is_qstart:
            return False
        return True

    def set_current_rule_name_and_current_value(self, current_rule_name:str, current_value:str)->bool:
        """Ручная установка текущего правила

        Args:
            current_rule_name (str)
            current_value (str)

        Returns:
            bool
        """
        if check_input_value(current_value):
            self.__current_state = current_rule_name
            self.__current_value = current_value
            return True
        return False

    def move_carriage_and_make_some_action(self, is_start:bool)->bool:
        """Эта функция будет выполнять какое-то действие по правилу, либо, если правило не
         будет найдено, или действие будет последним, функция вернет значение False, иначе True

        Args:
            is_start (bool)

        Returns:
            bool
        """
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






