from settings import dict_of_settings

class Tape:
    """Этот класс описывает ленту машины Тьюринга"""

    def __init__(self, string):
        """Эта функция инициализирует ленту"""
        self.len_of_tape = dict_of_settings.get('len_of_tape', 0)
        self.tape = [dict_of_settings.get('default_symbol', '-')]*self.len_of_tape+list(map(str, string))+[dict_of_settings.get('default_symbol', '-')]*self.len_of_tape

    def get_symbol_from_tape(self, position_of_carriage):
        """Эта функция получает символ по позиции"""
        try:
            return self.tape[position_of_carriage]
        except IndexError:
            print("\n Problem with getting symbol!")
            return None

    def set_symbol_in_tape(self, position_of_carriage, new_symbol):
        """Эта функция заменят текущий символ на этой позиции на новый"""
        try:
            self.tape[position_of_carriage] = new_symbol
        except IndexError:
            print("\n Problem with setting symbol!")



# tape = Tape("1222422")
# print(tape.tape)