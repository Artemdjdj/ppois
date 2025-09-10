"""
В этом модуле описан класс, который определяет алгоритм Маркова
"""
from Markov_algorithm_code.rule import Rule
from Markov_algorithm_code.markov_string import MarkovString
from Markov_algorithm_code.utils import binary_search
import string
from typing import List

class MarkovAlgorithm:
    """Этот класс описывает непосредственно алгорифм  Маркова
    """
    def __init__(self,markov_string:MarkovString=MarkovString(""), alphabet=None, default_symbol = "→", stop_symbol="*")->None:
        """Этот метод инициализирует сам алгорифм Маркова
        Args:
            markov_string (MarkovString, optional). Defaults to MarkovString("").
            alphabet (_type_, optional):. Defaults to None.
            default_symbol (str, optional). Defaults to "→".
            stop_symbol (str, optional). Defaults to "*".
        """
        self.__rules = list()
        self.__markov_string = markov_string
        self.__default_symbol = default_symbol
        self.__stop_symbol = stop_symbol
        self.__alphabet = alphabet if alphabet else "|/?!,." + string.ascii_lowercase + string.ascii_uppercase + \
                            string.digits

    def get_result_markov_string(self)->str:
        """Эта функция выводит готовую строку Маркова

        Returns:
            str
        """
        return str(self.__markov_string)

    def get_stop_symbol(self)->str:
        """Эта функция возвращает символ останова

        Returns:
            str
        """
        return self.__stop_symbol

    def get_markov_string_such_object(self)->str:
        """Эта функция возвращает строку Маркова, для тестирования нужен объект класса MarkovString

        Returns:
            str
        """
        return self.__markov_string

    def get_default_symbol(self)->str:
        """Эта функция возвращает разделяющий символ

        Returns:
            str
        """
        return self.__default_symbol

    def get_markov_rules(self)->List[Rule]:
        """Эта функция возвращает список правил

        Returns:
            List[Rule]
        """
        return self.__rules

    def add_new_rule(self, rule:Rule)->None:
        """_summary_

        Args:
            rule (Rule)
        """
        self.__rules.append(rule)

    def delete_rule_by_position(self, position:int)->None:
        """Эта функция удаляет правило по позиции в списке правил

        Args:
            position (int)
        """
        self.__rules.pop(position)

    def change_rule_by_position(self, position:int, new_rule:Rule)->None:
        """Эта функция изменяет правило

        Args:
            position (int): _description_
            new_rule (Rule): _description_
        """
        self.__rules[position] = new_rule

    def set_string_value(self)->None:
        """Эта функция устанавливает значение строки
        """
        letters = sorted(list(self.__alphabet))
        while True:
            is_good_string = True
            string_input = input("\nPlease enter your string, which approach alphabet:")
            for letter in string_input:
                if not binary_search(letters, letter):
                    is_good_string = False
                    break
            if is_good_string:
                break
            else:
                print("\n Sorry, but your string is not correct!")
        self.__markov_string.set_string_value(string_input)

    def set_string_value_for_test(self, input_string:str)->bool:
        """Эта функция используется чтобы проверить работу алгоритма в unittest

        Args:
            input_string (str)

        Returns:
            bool
        """
        letters = sorted(list(self.__alphabet))
        for letter in input_string:
            if not binary_search(letters, letter):
                return False
        self.__markov_string.set_string_value(input_string)
        return True

    def make_markov_algorithm(self)->bool:
        """Эта функция ищет подходящее правило и выполняет его
        Returns:
            bool
        """
        for rule in self.__rules:
            if self.__markov_string.replacing_one_string_with_another(rule.get_search_string(), \
                                                                      rule.get_replace_string(),self.__stop_symbol):
                if len(rule.get_replace_string())>0 and rule.get_replace_string()[-1] == self.__stop_symbol:
                    return True
                else:
                    return False
        return True

    def check_input_rule(self, list_of_split_rule)->bool:
        """Эта функция реализует проверку на корректность введенных правил

        Args:
            list_of_split_rule (_type_)

        Returns:
            bool
        """
        if len(list_of_split_rule) !=3:
            return False
        first_str = list_of_split_rule[0]
        second_str = list_of_split_rule[2]
        symbol = list_of_split_rule[1]
        if symbol != self.__default_symbol:
            return False
        letters = sorted(list(self.__alphabet))
        for letter in first_str:
            if not binary_search(letters, letter):
                return False
        for letter in second_str:
            if not binary_search(letters, letter):
                return False
        return True

    def filling_set(self, path_to_file)->bool:
        """Эта функция наполняет список правилами

        Args:
            path_to_file (_type_)

        Returns:
            bool
        """
        try:
            with open(path_to_file, 'r') as file:
                while True:
                    line = file.readline()
                    if not line:
                        break
                    list_of_keys = line.split()
                    if self.check_input_rule(list_of_keys):
                        rule = Rule(list_of_keys[0], list_of_keys[2])
                        self.__rules.append(rule)

            return True
        except FileNotFoundError:
            # print("\nSorry, but programm can't find the file!\n")
            return False