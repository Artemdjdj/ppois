"""Файл exceptions.py необходим для определения пользовательских классов исключений."""


class IncorrectVertex(Exception):
    """Класс пользовательского исключения

    Используется при некорректной работе с вершиной графа
    """

    def __init__(self, msg: str) -> None:
        """Инициализирует сообщение"""
        super().__init__(msg)
        self.msg: str = msg


class IncorrectEdge(Exception):
    """Класс пользовательского исключения

    Используется при некорректной работе с ребром графа
    """

    def __init__(self, msg: str) -> None:
        """Инициализирует сообщение"""
        super().__init__(msg)
        self.msg: str = msg


class EmptyContainer(Exception):
    """Класс пользовательского исключения

    Используется при пустом контейнере
    """

    def __init__(self, msg: str) -> None:
        """ Инициализирует сообщение"""
        super().__init__(msg)
        self.msg: str = msg


class IncorrectPosition(Exception):
    """Класс пользовательского исключения

    Используется при некорректной позиции итератора
    """

    def __init__(self, msg: str) -> None:
        """Инициализирует сообщение"""
        super().__init__(msg)
        self.msg: str = msg
