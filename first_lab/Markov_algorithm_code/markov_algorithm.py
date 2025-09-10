"""
В этом модуле описан класс, который определяет алгоритм Маркова
"""
from Markov_algorithm_code.rule import Rule
from Markov_algorithm_code.markov_string import MarkovString
import string
from Markov_algorithm_code.utils import binary_search

class MarkovAlgorithm:
    """Этот класс описывает непосредственно алгорифм  Маркова"""
    def __init__(self, alphabet=None, default_symbol = "→", stop_symbol="*"):
        """Этот метод инициализирует сам алгорифм Маркова"""
        self.__rules = list()
        self.__markov_string = MarkovString("")
        self.__default_symbol = default_symbol
        self.__stop_symbol = stop_symbol
        self.__alphabet = alphabet if alphabet else "|/?!,." + string.ascii_lowercase + string.ascii_uppercase + \
                            "".join([str(n) for n in range(0, 10)])
        # if not alphabet:
        #     self.__alphabet = "|/?!,." + string.ascii_lowercase + string.ascii_uppercase + \
        #                     "".join([str(n) for n in range(0, 10)])
        # else:
        #     self.__alphabet = alphabet

    def get_result_markov_string(self):
        """Эта функция выводит готовую строку Маркова"""
        return str(self.__markov_string)

    def get_stop_symbol(self):
        """Эта функция возвращает символ останова"""
        return self.__stop_symbol

    def get_markov_string_such_object(self):
        """Эта функция возвращает строку Маркова, для тестирования нужен объект класса MarkovString"""
        return self.__markov_string

    def get_default_symbol(self):
        """Эта функция возвращает разделяющий символ"""
        return self.__default_symbol

    def get_markov_rules(self):
        """Эта функция возвращает список правил"""
        return self.__rules

    def add_new_rule(self, rule):
        """Эта функция добавляет новое правило в общий список правил"""
        self.__rules.append(rule)

    def delete_rule_by_position(self, position):
        """Эта функция удаляет правило по позиции в списке правил"""
        self.__rules.pop(position)

    def change_rule_by_position(self, position, new_rule):
        """Эта функция изменяет правило"""
        self.__rules[position] = new_rule

    def set_string_value(self):
        """Эта функция устанавливает значение строки"""
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

    def set_string_value_for_test(self, input_string):
        """Эта функция используется чтобы проверить работу алгоритма в unittest"""
        letters = sorted(list(self.__alphabet))
        for letter in input_string:
            if not binary_search(letters, letter):
                return False
        self.__markov_string.set_string_value(input_string)
        return True

    def make_markov_algorithm(self)->bool:
        """Эта функция ищет подходящее правило и выполняет его"""
        for rule in self.__rules:
            if self.__markov_string.replacing_one_string_with_another(rule.get_search_string(), \
                                                                      rule.get_replace_string(),self.__stop_symbol):
                if len(rule.get_replace_string())>0 and rule.get_replace_string()[-1] == self.__stop_symbol:
                    return True
                else:
                    return False
        return True

    def check_input_rule(self, list_of_split_rule):
        """Эта функция реализует проверку на корректность введенных правил"""
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

    def filling_set(self, path_to_file):
        """Эта функция наполняет список правилами"""
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

# markov_algorithm_res = MarkovAlgorithm()
# markov_algorithm_res.set_string_value()
#
# markov_algorithm_res.get_result_markov_string()