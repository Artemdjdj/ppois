from settings import dict_of_settings
from rule import Rule
from tape import Tape


class TuringMachine:
    """Этот класс является главным, в нем реализована каретка, а также сам механизм машины Тьюринга """
    def __init__(self, carriage,string, start_state, start_value):
        self.carriage = carriage
        self.tape = Tape(string)
        self.rules= {}
        self.current_state = start_state
        self.current_value = start_value

    def __str__(self):
        """Эта функция делает отчет о состоянии машины Тьюринга"""
        return (f"На данный момент:\
        каретка находится на позиции: {self.carriage} \
        текущая операция: {self.current_state} \
        текущее значение: {self.current_value}")

    def extend_rules(self, tupple_rule, rule):
        """Эта функция добавляет правило в словарь правил для машины Тьюринга"""
        self.rules[tupple_rule] = rule

    def move_carriage_and_make_some_action(self, is_start):
        """Эта функция будет выполнять какое-то действие по правилу, либо, если правило не
         будет найдено, или действие будет последним, функция вернет значение False, иначе True"""
        if is_start:
            self.current_state = "qstart"
            self.current_value = self.tape.tape[self.carriage]
            return True
        rule = self.rules.get((self.current_state, self.current_value), None)
        if not rule:
            return False
        self.current_state = rule.next_rule_name
        self.tape.set_symbol_in_tape(self.carriage, rule.next_value)
        left_of_right_direction = 1 if rule.direction == 'right' else -1
        self.carriage += left_of_right_direction
        self.current_value = self.tape.tape[self.carriage]
        if self.current_state =="qfinish":
            return False
        return True






