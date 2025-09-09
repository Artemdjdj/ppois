from unittest import TestCase
from Turing_machine_code.turing_machine import TuringMachine
from Turing_machine_code.settings import get_default_symbol
from Turing_machine_code.rule import Rule
from Turing_machine_code.utils import check_input_rule


class Test_Turing_machine(TestCase):

    def test_get_tape(self):
        turing_machine = TuringMachine(0, "Hello world", "qstart", "g")
        self.assertEqual(''.join([x for x in turing_machine.get_tape_to_turing_machine() if x !=get_default_symbol()]), \
                         "Hello world")

    def test_check_input_rule(self):
        good_list_of_keys = ["qstart", "a", "q1", "x","left"]
        bad_list_of_keys = ["qstart", "a", "!", "x","right"]
        self.assertTrue(check_input_rule(good_list_of_keys))
        self.assertFalse(check_input_rule(bad_list_of_keys))

    def test_working_with_input_data(self):
        rule_1 = Rule("qstart", "a", "q1", "c", "right")
        rule_2 = Rule("q1", "a", "q2", "b", "right")
        rule_3 = Rule("q2", "a", "q3", "c", "right")
        rule_4 = Rule("q3", "a", "q1", "4", "right")

        rules = [
            [(rule_1.get_current_rule_name(), rule_1.get_current_value()), rule_1],
            [(rule_2.get_current_rule_name(), rule_2.get_current_value()), rule_2],
            [(rule_3.get_current_rule_name(), rule_3.get_current_value()), rule_3],
            [(rule_4.get_current_rule_name(), rule_4.get_current_value()), rule_4],
        ]
        turing_machine = TuringMachine(0, "aaaa", "qstart", "a")
        self.assertTrue(turing_machine.extend_rules_using_list_of_keys(rules))




