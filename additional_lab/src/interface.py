"""Файл interface.py необходим для представления базового консольного интерфейса пользователям."""


class Interface:
    """
    Предоставляет возможность получения списка всевозможных операций программы.
    """

    @staticmethod
    def get_menu():
        """
        Выводит список операций для работы со структурой данных Bloom Filter.
        """
        print("\n Bloom Filter\n")
        print("1 - Add new word")
        print("2 - Check is word in bloom filter")
        print("3 - Quit program\n")
