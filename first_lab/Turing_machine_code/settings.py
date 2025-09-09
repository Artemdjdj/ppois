
import string
# Этот файл отвечает за базовые настройки, например длина ленты в машине Тьюринга

# dict_of_settings={
#     'len_of_tape' : 10,
#     'default_symbol':"-",
#     'alphabet':string.ascii_lowercase+string.ascii_uppercase+"".join([str(n) for n in range(0, 10)])+dict_of_settings.get('default_symbol','-'),
#     'carriage_position' : 0,
# }
dict_of_settings = {'len_of_tape': 10, 'default_symbol': "-"}
dict_of_settings['alphabet'] = string.ascii_lowercase + string.ascii_uppercase + "".join([str(n) for n in range(0, 10)]) + dict_of_settings['default_symbol']
dict_of_settings['carriage_position'] = 0

def try_to_make_input_data_better(key, value):
    """Эта функция пытается сделать данные точно правильными"""
    if key == 'alphabet':
        return "".join(dict.fromkeys(value))
    elif key == 'default_symbol':
        return value[0]
    return value

def get_default_symbol():
    """Эта функция вернет из словаря спустой символ ленты"""
    return dict_of_settings.get('default_symbol', '-')

def get_settings():
    """Эта функция считывает базовые настройки, которые можно записать в файл settings.txt"""
    with open(r"C:\Users\Redmi\Desktop\ppois\first_lab\Turing_machine_code\settings.txt", 'r') as file:
        for _ in range(len(dict_of_settings)):
            res = file.readline().split()
            if len(res)<=1 or len(res)>2:
                continue
            key, value = res
            value = try_to_make_input_data_better(key, value)
            if isinstance(value, type(dict_of_settings[key])):
                dict_of_settings[key] = value