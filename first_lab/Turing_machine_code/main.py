"""@package docstring
Этот модуль выполняет функцию консольного приложения.
С помощью этого модуля можно протестировать машину Тьюринга, а также отредактировать список правил
"""

from Turing_machine_code.turing_machine import TuringMachine
from Turing_machine_code.settings import dict_of_settings, get_settings
from Turing_machine_code.rule import Rule
from Turing_machine_code.utils import check_input_rule
import logging
from logger import ColoredFormatter
import time
from typing import List, Tuple, Callable

def print_menu()->None:
    """Эта функция выводит меню операций на экран"""
    print("\n1. посмотреть список правил")
    print("2. добавить новое правило")
    print("3. удалить правило")
    print("4. изменть правило")
    print("5. закончить редактирование правил")

def create_new_rule()->Rule:
    """Эта функция безопасно создает правило"""
    current_state = input("Enter the current state: ")
    current_value = input("Enter the current value: ")
    next_rule_name = input("Enter the next state: ")
    next_value = input("Enter the next value: ")
    direction = input("Enter the direction: ")
    if check_input_rule(["number", current_state, current_value, next_rule_name, next_value, direction]):
        return Rule(current_state, current_value, next_rule_name, next_value, direction)
    else:
        return None

def work_with_input_rules(result_arr):
    """Эта функция редактирует правила"""
    beautiful_logger = logging.getLogger("logger")
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
                    if len(result_arr) <= 0:
                        beautiful_logger.warning("There are no rules!")
                        # для красивого вывода в консоль
                        time.sleep(0.05)
                        continue
                    for operation in result_arr:
                        beautiful_logger.debug(operation[1].__str__())
                case 2:
                    rule = create_new_rule()
                    if rule and [(rule.get_current_rule_name(), rule.get_current_value()), rule] not in result_arr:
                        result_arr.append([(rule.get_current_rule_name(), rule.get_current_value()), rule])
                    else:
                        # print("\nIncorrect rule! Try again!\n")
                        beautiful_logger.error("Incorrect rule or such rule always in rules! Try again!\n")
                case 3:
                    if not result_arr:
                        # print("\n You cant delete rule, because there are no rules!\n")
                        beautiful_logger.error("You cant delete rule, because there are no rules!\n")
                        # для красивого вывода в консоль
                        time.sleep(0.05)
                        continue
                    try:
                        number_of_rule = int(input("Enter the number of rule, which you want to cat from rules: "))
                        if 0 <= number_of_rule-1 < len(result_arr):
                            result_arr.pop(number_of_rule-1)
                        else:
                            # print("\n Number of rule is not correct!\n")
                            beautiful_logger.error("Number of rule is not correct!\n")
                    except ValueError:
                        # print("\nIncorrect value, please try again!\n")
                        beautiful_logger.error("Incorrect value, please try again!\n")
                case 4:
                    if not result_arr:
                        # print("\n You cant change rule, because there are no rules!\n")
                        beautiful_logger.error("You cant change rule, because there are no rules!\n")
                        # для красивого вывода в консоль
                        time.sleep(0.05)
                        continue
                    try:
                        number_of_rule = int(input("Enter the number of rule, which you want to edit: "))
                        if 0 <= number_of_rule - 1 < len(result_arr):
                            rule = create_new_rule()
                            if rule and [(rule.get_current_rule_name(), rule.get_current_value()), rule] not in result_arr:
                                result_arr[number_of_rule-1] = [(rule.get_current_rule_name(), rule.get_current_value()), rule]
                            else:
                                # print("\nIncorrect rule! Try again!\n")
                                beautiful_logger.error("Incorrect rule or such rule always in rules! Try again!\n")
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
    return result_arr
def main():
    """Эта главная функция, которая управляет ходом работы программы"""
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.DEBUG)
    file_handler = logging.FileHandler('Turing_machine.log', mode='w')
    file_formatter = logging.Formatter('%(name)s -----> %(asctime)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(file_formatter)
    # stream_handler = logging.StreamHandler()
    # stream_handler.setFormatter(ColoredFormatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s'))
    logger.addHandler(file_handler)
    # logger.addHandler(stream_handler)

    print("\n Enter the path to your input data:")
    parameters= input().split()
    if not parameters:
        # print("\n Problem with getting path!")
        logger.error("Problems with your input parameters!")
        return
    is_log = False
    if len(parameters) >=2:
        if parameters[1] =="-log":
            is_log = True
    path_to_file = parameters[0]
    get_settings()
    # print(dict_of_settings)
    logger.debug(f"dict of settings: {dict_of_settings}")
    res_arr_of_rules = []
    try:
        with open(path_to_file, 'r') as file:
            while True:
                line = file.readline()
                if not line:
                    break
                list_of_keys = line.split()
                if len(list_of_keys) !=6:
                    # print("\nWrong input!")
                    logger.error("Wrong input format!")
                    # print(list_of_keys)
                    return
                logger.info(f"Success getting parameters {list_of_keys}")
                if not check_input_rule(list_of_keys):
                    # print("\nValues should be in alphabet!!!")
                    logger.error("Values should be in alphabet!")
                    return
                rule = Rule(list_of_keys[1], list_of_keys[2], list_of_keys[3], list_of_keys[4], list_of_keys[5])
                rule_tuple = (list_of_keys[1], list_of_keys[2])
                res_arr_of_rules.append([rule_tuple, rule])

        print("\n Enter the start tape: ")
        input_string = input()
        carriage_position = dict_of_settings.get('carriage_position', 0) if dict_of_settings.get('carriage_position', 0) \
            < len(input_string) else 0
        carriage = carriage_position + dict_of_settings.get('len_of_tape', 0)

        turing_machine = TuringMachine(carriage, input_string, 'qstart', input_string[0])
        res_arr_of_rules = work_with_input_rules(res_arr_of_rules)
        # for el in res_arr_of_rules:
        #     tuple_rule = el[0]
        #     rule = el[1]
        #     if not is_qstart and rule.get_current_rule_name()=="qstart":
        #         is_qstart = True
        #     turing_machine.extend_rules(tuple_rule, rule)
        # if not is_qstart:
        #     # print("\n qstart not in input!!!")
        #     logger.error("qstart not in input!")
        #     return
        is_qstart = turing_machine.extend_rules_using_list_of_keys(res_arr_of_rules)
        if not is_qstart:
            logger.error("qstart not in input!")
            return
        is_start = False
        while True:
            if not is_start:
                turing_machine.move_carriage_and_make_some_action(True)
                is_start = True
            else:
                if not turing_machine.move_carriage_and_make_some_action(False):
                    break
                if is_log:
                    logger.debug(turing_machine.__str__())
        # print(turing_machine.tape.tape)
        # print("\n The Turing machine is successfully completed!")
        logger.debug(f"Result tape: {turing_machine.get_tape_to_turing_machine()}")
        logger.info("The Turing machine is successfully completed!")
    except FileNotFoundError:
        logger.error("\nWrong path to your file!\n")

if __name__ == '__main__':
    main()