"""@package docstring
Этот модуль выполняет функцию консольного приложения.
С помощью этого модуля можно протестировать алгорифмы Маркова, отредактировать уже существующие правила
"""

from Markov_algorithm_code import markov_algorithm
from Markov_algorithm_code.markov_algorithm import MarkovAlgorithm
from Markov_algorithm_code.rule import Rule
import logging
from logger import ColoredFormatter
import typing
import time

def print_menu():
    """
    Эта функция выводит меню операций на экран
    """
    print("\n1. посмотреть список правил")
    print("2. добавить новое правило")
    print("3. удалить правило")
    print("4. изменть правило")
    print("5. закончить редактирование правил")

def create_new_rule(markov_algorithm):
    """Эта функция безопасно создает правило"""
    search_string = input("\nEnter search string:")
    replace_string = input("\nEnter replace string:")
    if markov_algorithm.check_input_rule([search_string, markov_algorithm.get_default_symbol(), replace_string]):
        rule = Rule(search_string, replace_string)
        return rule
    else:
        # print("\nYour input data is invalid! Try again!")
        return None


def work_with_input_rules(markov_algorithm):
    """Эта функция редактирует правила"""
    beautiful_logger = logging.getLogger("logger_markov")
    beautiful_logger.setLevel(logging.DEBUG)
    beautiful_handler = logging.StreamHandler()
    beautiful_formatter = ColoredFormatter('%(asctime)s - %(levelname)s - %(message)s')
    beautiful_handler.setFormatter(beautiful_formatter)
    beautiful_logger.addHandler(beautiful_handler)
    choice = -1
    while choice !=5:
        print_menu()
        try:
            choice  = int(input("Please, enter the number of choice:"))
            match choice:
                case 1:
                    if len(markov_algorithm.get_markov_rules())<=0:
                        beautiful_logger.warning("There are no markov rules!")
                        # для красивого вывода в консоль
                        time.sleep(0.05)
                        continue
                    for i, rule in enumerate(markov_algorithm.get_markov_rules()):
                        beautiful_logger.debug(f"{i+1}. {rule.__str__()}")
                case 2:
                    rule =create_new_rule(markov_algorithm)
                    if rule not in markov_algorithm.get_markov_rules():
                        markov_algorithm.add_new_rule(rule)
                    else:
                        beautiful_logger.error("Incorrect rule or such rule always in list of rules! Try again!\n")
                case 3:
                    if not markov_algorithm.get_markov_rules():
                        # print("\n You cant delete rule, because there are no rules!\n")
                        beautiful_logger.error("You cant delete rule, because there are no rules!\n")
                        # для красивого вывода в консоль
                        time.sleep(0.05)
                        continue
                    try:
                        number_of_rule = int(input("Enter the number of rule, which you want to cat from rules: "))
                        if 0 <= number_of_rule-1 < len(markov_algorithm.get_markov_rules()):
                            markov_algorithm.delete_rule_by_position(number_of_rule-1)
                        else:
                            # print("\n Number of rule is not correct!\n")
                            beautiful_logger.error("Number of rule is not correct!\n")
                    except ValueError:
                        # print("\nIncorrect value, please try again!\n")
                        beautiful_logger.error("Incorrect value, please try again!\n")
                case 4:
                    if not markov_algorithm.get_markov_rules():
                        # print("\n You cant change rule, because there are no rules!\n")
                        beautiful_logger.error("You cant change rule, because there are no rules!\n")
                        # для красивого вывода в консоль
                        time.sleep(0.05)
                        continue
                    try:
                        number_of_rule = int(input("Enter the number of rule, which you want to edit: "))
                        if 0 <= number_of_rule - 1 < len(markov_algorithm.get_markov_rules()):
                            rule = create_new_rule(markov_algorithm)
                            if rule and rule not in markov_algorithm.get_markov_rules():
                                markov_algorithm.change_rule_by_position(number_of_rule-1, rule)
                            else:
                                # print("\nIncorrect rule! Try again!\n")
                                beautiful_logger.error("Incorrect rule or such rule always in list of rules! Try again!\n")
                        else:
                            # print("\n Number of rule is not correct!\n")
                            beautiful_logger.error("Number of rule is not correct!\n")
                    except ValueError:
                        # print("\nIncorrect value, please try again!\n")
                        beautiful_logger.error("Incorrect value, please try again!\n")
                case 5:
                    # print("\nYou successful leaved from changing your rules\n")
                    beautiful_logger.info("You successful leaved from changing your rules\n")
                case _:
                    # print("\nSorry, but you cant choose these operation!\n")
                    beautiful_logger.warning("Sorry, but you cant choose these operation!\n")

            # для красивого вывода в консоль
            time.sleep(0.05)
        except ValueError:
            # print("\nIncorrect value, please try again!\n")
            beautiful_logger.error("Incorrect value, please try again!\n")
    return markov_algorithm

def main():
    """Это главная функция, вней тестируется сам алгоритм Маркова"""
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.DEBUG)
    file_handler = logging.FileHandler('Markov_algorithm.log', mode='w')
    file_formatter = logging.Formatter('%(name)s -----> %(asctime)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(file_formatter)
    logger.addHandler(file_handler)

    markov_algorithm_res = MarkovAlgorithm()
    parameters = input("\n Enter the path to your file:").split()
    if not parameters:
        # print("\n Problem with getting path!")
        logger.error("Problems with your input parameters!")
        return
    is_log = False
    if len(parameters) >= 2:
        if parameters[1] == "-log":
            is_log = True
    path_to_file = parameters[0]
    is_correct_path = markov_algorithm_res.filling_set(path_to_file)
    if not is_correct_path:
        return
    markov_algorithm_res.set_string_value()
    markov_algorithm_res = work_with_input_rules(markov_algorithm_res)
    # print(markov_algorithm_res.markov_string.__str__())
    # print([[rule.search_string, rule.replace_string] for rule in markov_algorithm_res.rules])
    while True:
        result_of_algorithm = markov_algorithm_res.make_markov_algorithm()
        logger.debug(f"Result of algorithm: {markov_algorithm_res.get_result_markov_string()}")
        if result_of_algorithm:
            break

    logger.info(f"The result of the algorithm is: {markov_algorithm_res.get_result_markov_string()}")

if __name__ == '__main__':
    main()