
class Rule:
    """Этот класс описывает правила которые будет выполнять машина Тьюринга"""
    def __init__(self, current_rule_name, current_value, next_rule_name, next_value, direction):
        """Эта функция инициализирует правила"""
        self.current_rule_name =current_rule_name
        self.current_value = current_value
        self.next_rule_name = next_rule_name
        self.next_value = next_value
        self.direction = direction

    def __str__(self):
        """Эта функция выводит соответствующее правило"""
        print(f"Текущее правило: {self.current_rule_name} текущее значение: {self.current_value}     ----> \
        Следующее правило: {self.next_rule_name}  новое значение: {self.next_value}  направление:\
        {self.direction}")


# rule = Rule("q0", 1,"q2", 2, "right")
# rule.__str__()