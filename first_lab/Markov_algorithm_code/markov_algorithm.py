from rule import Rule
from markov_string import MarkovString
import string
from utils import binary_search

class MarkovAlgorithm:
    """Этот класс описывает непосредственно алгорифм  Маркова"""
    def __init__(self, alphabet=None, default_symbol = "→", stop_symbol="*"):
        """Этот метод инициализирует сам алгорифм Маркова"""
        self.rules = list()
        self.markov_string = MarkovString("")
        self.default_symbol = default_symbol
        self.stop_symbol = stop_symbol
        if not alphabet:
            self.alphabet = "|/?!,." + string.ascii_lowercase + string.ascii_uppercase + \
                            "".join([str(n) for n in range(0, 10)])
        else:
            self.alphabet = alphabet

    def set_string_value(self):
        """Эта функция устанавливает значение строки"""
        letters = sorted(list(self.alphabet))
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
        self.markov_string.set_string_value(string_input)

    def make_markov_algorithm(self)->bool:
        """Эта функция ищет подходящее правило и выполняет его"""
        for rule in self.rules:
            if self.markov_string.replacing_one_string_with_another(rule.search_string, rule.replace_string,self.stop_symbol):
                if len(rule.replace_string)>0 and rule.replace_string[-1] == self.stop_symbol:
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
        if symbol != self.default_symbol:
            return False
        letters = sorted(list(self.alphabet))
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
                        self.rules.append(rule)

            return True
        except FileNotFoundError:
            print("\nSorry, but programm can't find the file!\n")
            return False


