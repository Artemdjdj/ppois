"""
Этот модуль предназначен для тестирования классов и функций машины Тьюринга
"""

from unittest import TestCase
from Turing_machine_code.turing_machine import TuringMachine
from Turing_machine_code.settings import get_default_symbol
from Turing_machine_code.rule import Rule
from Turing_machine_code.utils import check_input_rule
from Turing_machine_code.tape import Tape

rule_1 = Rule("qstart", "a", "q1", "c", "right")
rule_2 = Rule("q1", "a", "q2", "b", "right")
rule_3 = Rule("q2", "a", "q3", "c", "right")
rule_4 = Rule("q3", "a", "q1", "4", "right")
rule_7 = Rule("q11", "e", "qfinish", "c", "left")

rules = [
    [(rule_1.get_current_rule_name(), rule_1.get_current_value()), rule_1],
    [(rule_2.get_current_rule_name(), rule_2.get_current_value()), rule_2],
    [(rule_3.get_current_rule_name(), rule_3.get_current_value()), rule_3],
    [(rule_4.get_current_rule_name(), rule_4.get_current_value()), rule_4],
    [(rule_7.get_current_rule_name(), rule_7.get_current_value()), rule_7],

]
class Test_Turing_machine(TestCase):
    """Этот класс используется для тестирования функций"""
    def test_get_tape(self):
        """Этот тест проверяет ленту машины Тьюринга"""
        turing_machine = TuringMachine(0, "qstart", "g", Tape("Hello world"))
        self.assertEqual(''.join([x for x in turing_machine.get_tape_to_turing_machine() if x !=get_default_symbol()]), \
                         "Hello world")
    def test_get_tape2(self):
        """Этот тест проверяет ленту машины Тьюринга"""
        turing_machine = TuringMachine(2,"qstart", "g", Tape("result"))
        self.assertEqual(''.join([x for x in turing_machine.get_tape_to_turing_machine() if x !=get_default_symbol()]), \
                         "result")

    def test_check_input_rule_True(self):
        """Этот тест проверяет на корректность входные данные, а именно правила"""
        good_list_of_keys = ["1:","qstart", "a", "q1", "x","left"]
        self.assertTrue(check_input_rule(good_list_of_keys))

    def test_check_input_rule_False(self):
        """Этот тест проверяет на корректность входные данные, а именно правила"""
        bad_list_of_keys = ["1:","qstart", "a", "q2", "&","right"]
        self.assertFalse(check_input_rule(bad_list_of_keys))

    def test_check_input_rule_False_problems_with_direction_lower(self):
        """Этот тест проверяет на корректность входные данные, а именно правила"""
        bad_list_of_keys = ["1:","qstart", "a", "q2", "a","Right"]
        self.assertTrue(check_input_rule(bad_list_of_keys))

    def test_check_input_rule_False_problems_with_direction(self):
        """Этот тест проверяет на корректность входные данные, а именно правила"""
        bad_list_of_keys = ["1:","qstart", "a", "q2", "a","hello"]
        self.assertFalse(check_input_rule(bad_list_of_keys))

    def test_working_with_input_data(self):
        """Этот тест проверяет возможность расширения словаря правил"""
        turing_machine = TuringMachine(0, "q1", "a", Tape("aaaa"))
        self.assertTrue(turing_machine.extend_rules_using_list_of_keys(rules))

    def test_working_with_input_data2(self):
        """Этот тест проверяет возможность расширения словаря правил"""
        turing_machine = TuringMachine(0, "qstart", "a", Tape("aaaa"))
        self.assertFalse(turing_machine.extend_rules_using_list_of_keys(rules[1:]))

    def test_how_work_function_make_action_False(self):
        """Этот тест проверяет непосредственно работу машины Тьюринга для некорректных значений"""
        turing_machine = TuringMachine(0, "qstart", "a", Tape("aaaa"))
        if turing_machine.extend_rules_using_list_of_keys(rules):
            # test case when move return False
            turing_machine.set_current_rule_name_and_current_value("q10", "e")
            self.assertFalse(turing_machine.move_carriage_and_make_some_action(False))

    def test_how_work_function_make_action_True(self):
        """Этот тест проверяет непосредственно работу машины Тьюринга для верных значений"""
        turing_machine = TuringMachine(0, "qstart", "a", Tape("aaaa"))
        if turing_machine.extend_rules_using_list_of_keys(rules):
            # test case when move return True
            turing_machine.set_current_rule_name_and_current_value("q1", "a")
            self.assertTrue(turing_machine.move_carriage_and_make_some_action(False))

    def test_how_work_function_make_action_False_and_Finish_value(self):
        """Этот тест проверяет непосредственно работу машины Тьюринга для некорректных значений"""
        turing_machine = TuringMachine(0, "qstart", "a", Tape("aaaa"))
        if turing_machine.extend_rules_using_list_of_keys(rules):
            turing_machine.set_current_rule_name_and_current_value("q11", "e")
            self.assertFalse(turing_machine.move_carriage_and_make_some_action(False))

    def test_get_symbol_from_tape(self):
        """Этот тест проверяет функцию получения символа из ленты по положению каретки"""
        turing_machine = TuringMachine(0, "qstart", "a", Tape("aaap"))
        self.assertIsNone(turing_machine.get_tape_from_turing_machine().get_symbol_from_tape(50))

    def test_get_symbol_from_tape2(self):
        """Этот тест проверяет функцию получения символа из ленты по положению каретки"""
        turing_machine = TuringMachine(0, "qstart", "a", Tape("aaap"))
        self.assertIsNotNone(turing_machine.get_tape_from_turing_machine().get_symbol_from_tape(0))

    def test_equal_of_two_turing_rules(self):
        """Этот тест проверяет на уникальность два правила"""
        self.assertFalse(rule_1.__eq__(rule_2))

    def test_equal_of_two_turing_rules2(self):
        """Этот тест проверяет на уникальность два правила"""
        rule_5 = Rule("q5", "a", "q6", "c", "right")
        rule_6 = Rule("q5", "a", "q6", "c", "right")
        self.assertTrue(rule_5.__eq__(rule_6))

    def test_equal_of_two_turing_rules_where_one_parameter_is_unique(self):
        """Этот тест проверяет на уникальность два правила"""
        rule_5 = Rule("q5", "a", "q6", "c", "right")
        rule_6 = Rule("q5", "b", "q6", "c", "right")
        self.assertFalse(rule_5.__eq__(rule_6))

    def test_check_turing_current_name(self):
        """Этот тест проверяетвозвращаемое текущее имя правила"""
        rule = Rule("q5", "a", "q6", "c", "right")
        self.assertEqual(rule.get_current_rule_name(), "q5")