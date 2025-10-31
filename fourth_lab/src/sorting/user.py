"""Файл user.py необходим для определения класса User."""
from dataclasses import dataclass


@dataclass(order=True)
class User:
    """Класс представляет пользователя для демонстрации сортровок.

        Attributes:
            username (str): Имя пользователя (в системе).
            name (str): Имя пользователя.
            age (int): Возраст пользователя.
            id (int): Уникальный идентификационный номер.
    """
    username: str
    name: str
    age: int
    id: int

    def __repr__(self):
        """
        Функция формирует описание пользователя

        Returns:
            str: Описание пользователя.
        """
        return f"Username: {self.username}, Name: {self.name}, Age: {self.age}, ID: {self.id}"
