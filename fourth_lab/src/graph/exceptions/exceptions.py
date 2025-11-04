
class IncorrectVertex(Exception):
    def __init__(self, msg: str) -> None:
        super().__init__(msg)
        self.msg: str = msg

class IncorrectEdge(Exception):
    def __init__(self, msg: str) -> None:
        super().__init__(msg)
        self.msg: str = msg

class EmptyContainer(Exception):
    def __init__(self, msg: str) -> None:
        super().__init__(msg)
        self.msg: str = msg