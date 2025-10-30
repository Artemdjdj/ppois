from dataclasses import dataclass


@dataclass(order=True)
class User:
    username: str
    name: str
    age: int
    id: int

    def __repr__(self):
        return f"Username: {self.username}, Name: {self.name}, Age: {self.age}, ID: {self.id}"
