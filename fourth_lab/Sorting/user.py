from dataclasses import dataclass

@dataclass(order=True)
class User:
    user_id: int
    username: str
    name: str
    age: int

    def __repr__(self):
        return f"ID: {self.user_id}, Username: {self.username}, Name: {self.name}, Age: {self.age}"
