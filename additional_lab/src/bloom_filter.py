"""Файл bloom_filter.py необходим для представления фильтра Блума."""


class BloomFilter:
    """
    Структура данных для проверки, что значение отсутсвует в структуре. Фильтр Блума
    не может точно определить есть ли объект в структуре, но может точно определить,
    что объект не существует в структуре.

    Attributes:
        __number_of_hash_functions (int): Количество хеш-функций.
        __size_of_bloom_filter (int): Количество ячеек в фильтре Блума.
        __bloom_filter (List[int]): Список ячеек фильтра Блума.
    """

    def __init__(self, number_of_hash_functions: int = 5, size_of_bloom_filter: int = 10000) -> None:
        """
        Инициализирует фильтр Блума.

        Args:
            number_of_hash_functions (int): Количество хеш-функций, изначально 5.
            size_of_bloom_filter (int): Размер фильтра Блума, изначально 10000.
        """
        self.__number_of_hash_functions = number_of_hash_functions
        self.__size_of_bloom_filter = size_of_bloom_filter
        self.__bloom_filter = [0] * self.__size_of_bloom_filter

    def __hash_djb2(self, s: str) -> int:
        """
        Хеширует строку и возвращает номер ячейки.

        Args:
            s (str): Хешируемая строка.

        Returns:
            int: Числовое значение (номер ячейки)
        """
        start_hash = 5381
        for x in s:
            start_hash = start_hash * 33 + ord(x)
        return start_hash % self.__size_of_bloom_filter

    def __hash(self, item: str, number_of_hash_function: int) -> int:
        """
        Хеширует строку и возвращает номер ячейки.

        Args:
            item (str): Хешируемая строка.
            number_of_hash_function (int): Номер хешируемой функции.

        Returns:
            int: Номер ячейки.
        """
        return self.__hash_djb2(str(item) + str(number_of_hash_function))

    def add_value(self, item: str) -> None:
        """
        Добавляет новое значение.

        Args:
            item (str): Исходная строка.
        """
        for number_of_hash_function in range(self.__number_of_hash_functions):
            result_index = self.__hash(item, number_of_hash_function)
            self.__bloom_filter[result_index] = 1

    def check_value(self, item: str) -> bool:
        """
        Хеширует строку и возвращает номер ячейки.

        Args:
            item (str): Хешируемая строка.

        Returns:
            bool: True, если значение возможно есть в фильтре Блума, False - значение точно отсутствует
        """
        for number_of_hash_function in range(self.__number_of_hash_functions):
            result_index = self.__hash(item, number_of_hash_function)
            if self.__bloom_filter[result_index] == 0:
                return False
        return True
