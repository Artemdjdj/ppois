from src.sorting.sorting import GnomeSorting, PigeonholeSorting
from src.sorting.user import User
from src.graph.graph import Graph


def main():
    arr = ["a", "b", "c", "d"]
    arr = GnomeSorting().sort(arr, reverse=False)
    print(arr)
    arr2 = [User("alice", "Alice", 20, 43242), User("bob", "Bob", 37, 2432), User("artem", "Artem", 18, 1111)]
    arr2 = PigeonholeSorting().sort(arr2, lambda x: x.age, )
    print(arr2)
    str_graph = Graph[str]()
    str_graph.add_vertex("Moscow")
    str_graph.add_vertex("Minsk")
    str_graph.add_edge(0, 1)
    print(str_graph.number_of_vertices(), str_graph.number_of_edges())


if __name__ == '__main__':
    main()
