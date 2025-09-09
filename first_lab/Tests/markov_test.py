"""@package docstring
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
    def test_filling_set_(self):
        """Этот тест проверяет функцию заполнения правил"""
        self.assertFalse(MarkovAlgorithm().filling_set("hello world.txt"))

    # def test_filling_set_True(self):
    #     """Этот тест проверяет функцию заполнения правил"""
    #     self.assertTrue(MarkovAlgorithm().filling_set("C:/Users/Redmi/Desktop/ppois/first_lab/input/Markov_input.txt"))

    def test_set_value_to_markov_string(self):
        """Этот тест проверяет функцию присваивания значений строке маркова"""
        markov_algorithm = MarkovAlgorithm()
        self.assertTrue(markov_algorithm.set_string_value_for_test("hello"))

    def test_markov_algorithm(self):
        """Этот тест проверяет работоспособность алгоритма Маркова"""
        markov_algorithm = MarkovAlgorithm()
        markov_algorithm.filling_set("C:/Users/Redmi/Desktop/ppois/first_lab/input/Markov_input.txt")
        if markov_algorithm.set_string_value_for_test("1"):
            self.assertFalse(markov_algorithm.make_markov_algorithm())

    def test_equal_of_two_markov_rules(self):
        """Этот проверяет на равенство два правила"""
        rule_1 = Rule("a", "b")
        rule_2 = Rule("b", "a")
        self.assertFalse(rule_1.__eq__(rule_2))

    def test_replacing_markov_string_with_another(self):
        """Этот тест проверяет функцию замены одной строки на другую в алгорифме Маркова"""
        markov_algorithm = MarkovAlgorithm()
        markov_algorithm.set_string_value_for_test("hello")
        self.assertTrue(markov_algorithm.get_markov_string_such_object().replacing_one_string_with_another("h",\
                                                                                      "world",\
                                                                                      markov_algorithm.get_stop_symbol() \
                                                                                                      ))

    def test_binary_search(self):
        """Этот тест проверяет функцию бинарного поиска"""
        letters = string.ascii_lowercase
        some_char = "a"
        self.assertTrue(binary_search(letters, some_char))
