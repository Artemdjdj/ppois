class Rule:
    """Этот класс описывает правило"""
    def __init__(self, search_string, replace_string):
        """Эта функция описывает инициализацию правила"""
        self.search_string = search_string
        self.replace_string = replace_string

    def __str__(self):
        """"Эта функция выводит правила в красивом виде"""
        return f" Искомая подстрока: {self.search_string}  ---> Новая подстрока: {self.replace_string}"
