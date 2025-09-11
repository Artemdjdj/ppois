"""
Этот модуль предназначен для тестирования классов и функций алгорифма Маркова
"""

from unittest import TestCase
from Markov_algorithm_code import markov_algorithm
from Markov_algorithm_code.markov_algorithm import MarkovAlgorithm
from Markov_algorithm_code.markov_string import MarkovString
from Markov_algorithm_code.rule import Rule
from Markov_algorithm_code.utils import binary_search
import string

class Test_Markov_algorifm(TestCase):
    """Этот класс используется для тестирования функций"""
    def test_filling_set_False(self):
        """Этот тест проверяет функцию заполнения правил"""
        self.assertFalse(MarkovAlgorithm().filling_set("hello world.txt"))

    def test_filling_set_True(self):
        """Этот тест проверяет функцию заполнения правил"""
        self.assertTrue(MarkovAlgorithm().filling_set("input/Markov_input.txt"))

    def test_set_value_to_markov_string_True(self):
        """Этот тест проверяет функцию присваивания значений строке маркова"""
        self.assertTrue(MarkovAlgorithm().set_string_value_for_test("hello"))

    def test_set_value_to_markov_string_False(self):
        """Этот тест проверяет функцию присваивания значений строке маркова"""
        self.assertFalse(MarkovAlgorithm().set_string_value_for_test("&&&"))

    def test_markov_algorithm_False(self):
        """Этот тест проверяет работоспособность алгоритма Маркова"""
        markov_algorithm = MarkovAlgorithm()
        markov_algorithm.filling_set("input/Markov_input.txt")
        if markov_algorithm.set_string_value_for_test("1"):
            self.assertFalse(markov_algorithm.make_markov_algorithm())

    def test_markov_algorithm_True(self):
        """Этот тест проверяет работоспособность алгоритма Маркова"""
        markov_algorithm = MarkovAlgorithm()
        markov_algorithm.filling_set("input/Markov_input.txt")
        if markov_algorithm.set_string_value_for_test("7898"):
            self.assertTrue(markov_algorithm.make_markov_algorithm())

    def test_equal_of_two_markov_rules_False(self):
        """Этот проверяет на равенство два правила"""
        rule_1 = Rule("a", "b")
        rule_2 = Rule("b", "a")
        self.assertFalse(rule_1.__eq__(rule_2))

    def test_equal_of_two_markov_rules_True(self):
        """Этот проверяет на равенство два правила"""
        rule_1 = Rule("ak", "bc")
        rule_2 = Rule("ak", "bc")
        self.assertTrue(rule_1.__eq__(rule_2))

    def test_equal_of_two_markov_rules_False_one_parameter_is_unique(self):
        """Этот проверяет на равенство два правила"""
        rule_1 = Rule("ak", "bc")
        rule_2 = Rule("ak", "b")
        self.assertFalse(rule_1.__eq__(rule_2))

    def test_replacing_markov_string_with_another_True(self):
        """Этот тест проверяет функцию замены одной строки на другую в алгорифме Маркова"""
        markov_algorithm = MarkovAlgorithm()
        markov_algorithm.set_string_value_for_test("hello")
        self.assertTrue(markov_algorithm.get_markov_string_such_object().replacing_one_string_with_another("h",\
                                                                                      "world",\
                                                                                      markov_algorithm.get_stop_symbol() \
                                                                                                      ))
    def test_replacing_markov_string_with_another_False(self):
        """Этот тест проверяет функцию замены одной строки на другую в алгорифме Маркова"""
        markov_algorithm = MarkovAlgorithm()
        markov_algorithm.set_string_value_for_test("world")
        self.assertFalse(markov_algorithm.get_markov_string_such_object().replacing_one_string_with_another("h",\
                                                                                      "world",\
                                                                                      markov_algorithm.get_stop_symbol() \
                                                                                                      ))

    def test_binary_search_True(self):
        """Этот тест проверяет функцию бинарного поиска"""
        letters = string.ascii_lowercase
        some_char = "a"
        self.assertTrue(binary_search(letters, some_char))

    def test_binary_search_False(self):
        """Этот тест проверяет функцию бинарного поиска"""
        letters = string.ascii_lowercase
        some_char = "A"
        self.assertFalse(binary_search(letters, some_char))

    def test_how_print_rules(self):
        """Этот тест проверяет функцию, которая аозвращает правило в красивом виде"""
        rule= Rule("hel", "world")
        self.assertEqual(str(rule)," Искомая подстрока: hel  ---> Новая подстрока: world")
