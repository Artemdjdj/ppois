from src.graph.exceptions.exceptions import IncorrectEdge
from src.graph.graph import Graph
from src.graph.vertex import Vertex
from src.graph.edge import Edge
from src.graph.exceptions.exceptions import IncorrectVertex, IncorrectEdge, IncorrectPosition, EmptyContainer
import copy
import pytest


def create_sample_graph() -> Graph[int]:
    graph = Graph[int]()
    graph.add_vertex(1)
    graph.add_vertex(2)
    graph.add_vertex(3)
    graph.add_edge(1, 2)
    return graph


def test_copy_graph():
    graph1 = create_sample_graph()
    graph2 = copy.deepcopy(graph1)
    assert graph1 == graph2
    assert graph1 is not graph2


def test_not_eq_graphs():
    graph1 = create_sample_graph()
    graph2 = copy.deepcopy(graph1)
    graph2.add_edge(0, 2)
    assert graph1 != graph2


def test_ge_graphs():
    graph1 = create_sample_graph()
    graph2 = copy.deepcopy(graph1)
    assert graph2 >= graph1


def test_gt_graphs():
    graph1 = create_sample_graph()
    graph2 = copy.deepcopy(graph1)
    graph2.add_vertex(12)
    assert graph2 > graph1


def test_le_graphs():
    graph1 = create_sample_graph()
    graph2 = copy.deepcopy(graph1)
    assert graph1 <= graph2


def test_lt_graphs():
    graph1 = create_sample_graph()
    graph2 = copy.deepcopy(graph1)
    graph2.add_vertex(523543)
    assert graph1 < graph2


def test_str_empty_graph():
    """Тест для пустого графа"""
    graph = Graph[int]()
    result = str(graph)
    assert result == "Graph is empty"


def test_str_graph_with_vertices():
    """Тест для графа с вершинами и рёбрами"""
    graph = Graph[int]()
    graph.add_vertex(1)
    graph.add_vertex(2)
    graph.add_vertex(3)
    graph.add_edge(1, 2)

    result = str(graph)

    # Проверяем, что есть вступление
    assert "The graph is represented as an incidence matrix:" in result

    # Проверяем, что результат содержит числа из матрицы
    assert result.startswith("The graph is represented as an incidence matrix:\n")

    # Проверяем структуру (должны быть строки с числами)
    lines = result.split('\n')
    assert len(lines) > 1  # Заголовок + хотя бы одна строка матрицы


def test_str_format():
    graph = Graph[int]()
    graph.add_vertex(1)
    graph.add_vertex(2)
    graph.add_edge(0, 1)
    result = str(graph)
    lines = result.strip().split('\n')
    assert len(lines) >= 2
    matrix_lines = lines[1:]
    for line in matrix_lines:
        if line:
            assert ' ' in line or len(line.split()) == 1


def test_str_called_implicitly():
    graph = Graph[int]()
    result = str(graph)
    assert result == "Graph is empty"
    result2 = graph.__str__()
    assert result == result2


def test_empty_graph():
    graph1 = Graph[int]()
    assert graph1.is_empty()


def test_clear_graph():
    graph1 = create_sample_graph()
    assert not graph1.is_empty()
    graph1.clear()
    assert graph1.is_empty()


def test_number_of_vertices():
    graph1 = create_sample_graph()
    assert 3 == graph1.number_of_vertices()


def test_number_of_edges():
    graph1 = create_sample_graph()
    assert 1 == graph1.number_of_edges()


def test_vertex_degree():
    graph1 = create_sample_graph()
    assert 1 == graph1.vertex_degree(1)


def test_edge_degree():
    graph1 = create_sample_graph()
    assert 1 == graph1.edge_degree(0)


def test_add_exist_vertex():
    graph1 = create_sample_graph()
    with pytest.raises(IncorrectVertex):
        graph1.add_vertex(1)


def test_add_exist_edge():
    graph1 = create_sample_graph()
    with pytest.raises(IncorrectEdge):
        graph1.add_edge(1, 2)


def test_remove_vertex():
    graph1 = create_sample_graph()
    assert graph1.number_of_vertices() == 3
    graph1.remove_vertex(1)
    assert graph1.number_of_vertices() == 2


def test_remove_not_exist_vertex():
    graph1 = create_sample_graph()
    assert graph1.number_of_vertices() == 3
    with pytest.raises(IncorrectVertex):
        graph1.remove_vertex(7)
    assert graph1.number_of_vertices() == 3


def test_remove_edge():
    graph1 = create_sample_graph()
    assert graph1.number_of_edges() == 1
    graph1.remove_edge(0)
    assert graph1.number_of_edges() == 0


def test_remove_not_exist_edge():
    graph1 = create_sample_graph()
    assert graph1.number_of_edges() == 1
    with pytest.raises(IncorrectEdge):
        graph1.remove_edge(7)
    assert graph1.number_of_edges() == 1


def test_bidirectional_iterator_for_iterating_over_vertices():
    graph1 = create_sample_graph()
    iterator = graph1.bidirectional_iterator_for_iterating_over_vertices()
    assert 1 == next(iterator).data
    assert 2 == next(iterator).data
    assert 2 == iterator.previous().data
    iterator.position = 0
    assert 1 == next(iterator).data


def test_reverse_bidirectional_iterator_for_iterating_over_vertices():
    graph1 = create_sample_graph()
    iterator = graph1.reverse_bidirectional_iterator_for_iterating_over_vertices()
    assert 3 == next(iterator).data
    assert 2 == next(iterator).data
    assert 2 == iterator.previous().data


def test_const_bidirectional_iterator_for_iterating_over_vertices():
    graph1 = create_sample_graph()
    iterator = graph1.const_bidirectional_iterator_for_iterating_over_vertices()
    assert 1 == next(iterator).data
    assert 2 == next(iterator).data
    with pytest.raises(AttributeError):
        iterator.position = 0
    assert 3 == next(iterator).data



def test_const_reverse_bidirectional_iterator_for_iterating_over_vertices():
    graph1 = create_sample_graph()
    iterator = graph1.const_reverse_bidirectional_iterator_for_iterating_over_vertices()
    assert 3 == next(iterator).data
    with pytest.raises(AttributeError):
        iterator.position = 2
    assert 2 == next(iterator).data


def test_bidirectional_iterator_for_traversing_edges():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    iterator = graph1.bidirectional_iterator_for_traversing_edges()
    assert 0 == next(iterator).id
    assert 1 == next(iterator).id
    assert 1 == iterator.previous().id


def test_reverse_bidirectional_iterator_for_traversing_edges():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    iterator = graph1.reverse_bidirectional_iterator_for_traversing_edges()
    assert 1 == next(iterator).id
    assert 0 == next(iterator).id
    assert 0 == iterator.previous().id


def test_const_bidirectional_iterator_for_traversing_edges():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    iterator = graph1.const_bidirectional_iterator_for_traversing_edges()
    assert 0 == next(iterator).id
    assert 1 == next(iterator).id
    with pytest.raises(AttributeError):
        iterator.position = 2


def test_const_reverse_bidirectional_iterator_for_traversing_edges():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    iterator = graph1.const_reverse_bidirectional_iterator_for_traversing_edges()
    assert 1 == next(iterator).id
    assert 0 == next(iterator).id
    with pytest.raises(AttributeError):
        iterator.position = 2


def test_bidirectional_iterator_for_iter_over_edges_incident_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.bidirectional_iterator_for_iter_over_edges_incident_to_vertex(0)
    assert 1 == next(iterator).id
    assert 2 == next(iterator).id
    assert 2 == iterator.previous().id
    iterator.position = 2

def test_incorrect_index_of_vertex():
    graph1 = Graph()
    with pytest.raises(IncorrectVertex):
        graph1.bidirectional_iterator_for_iter_over_edges_incident_to_vertex(0)

def test_empty_container_in_special_graph():
    graph1 = Graph()
    graph1.add_vertex(52343)
    graph1.add_vertex(2)
    iterator = graph1.bidirectional_iterator_for_iter_over_edges_incident_to_vertex(0)
    with pytest.raises(EmptyContainer):
        assert 1 == next(iterator).id


def test_reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(0)
    assert 2 == next(iterator).id
    assert 1 == next(iterator).id
    assert 1 == iterator.previous().id


def test_const_bidirectional_iterator_for_iter_over_edges_incident_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.const_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(0)
    assert 1 == next(iterator).id
    assert 2 == next(iterator).id
    assert 2 == iterator.previous().id
    with pytest.raises(AttributeError):
        iterator.position = 2


def test_const_reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.const_reverse_bidirectional_iterator_for_iter_over_edges_incident_to_vertex(0)
    assert 2 == next(iterator).id
    assert 1 == next(iterator).id
    assert 1 == iterator.previous().id
    with pytest.raises(AttributeError):
        iterator.position = 2

def test_bidirectional_iterator_over_vertices_adjacent_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.bidirectional_iterator_over_vertices_adjacent_to_vertex(0)
    assert 2 == next(iterator).id
    assert 1 == next(iterator).id
    assert 1 == iterator.previous().id
    iterator.position = 2

def test_reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex(0)
    assert 1 == next(iterator).id
    assert 2 == next(iterator).id
    assert 2 == iterator.previous().id

def test_const_bidirectional_iterator_over_vertices_adjacent_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.const_bidirectional_iterator_over_vertices_adjacent_to_vertex(0)
    assert 2 == next(iterator).id
    assert 1 == next(iterator).id
    assert 1 == iterator.previous().id
    with pytest.raises(AttributeError):
        iterator.position = 2

def test_const_reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex():
    graph1 = create_sample_graph()
    graph1.add_edge(0, 2)
    graph1.add_edge(0, 1)
    iterator = graph1.const_reverse_bidirectional_iterator_over_vertices_adjacent_to_vertex(0)
    assert 1 == next(iterator).id
    assert 2 == next(iterator).id
    assert 2 == iterator.previous().id
    with pytest.raises(AttributeError):
        iterator.position = 2

def test_remove_vertex_by_iterator():
    graph1 = create_sample_graph()
    iterator = graph1.bidirectional_iterator_for_iterating_over_vertices()
    assert graph1.number_of_vertices() == 3
    graph1.remove_vertex_by_iterator(iterator)
    assert graph1.number_of_vertices() == 2

def test_remove_edge_by_iterator():
    graph1 = create_sample_graph()
    iterator = graph1.bidirectional_iterator_for_traversing_edges()
    assert graph1.number_of_edges() == 1
    graph1.remove_edge_by_iterator(iterator)
    assert graph1.number_of_edges() == 0

def test_remove_vertex_by_iterator_incorrect_position():
    graph1 = create_sample_graph()
    iterator = graph1.bidirectional_iterator_for_iterating_over_vertices()
    iterator.position = 10
    with pytest.raises(IncorrectPosition):
        graph1.remove_vertex_by_iterator(iterator)

def test_remove_edge_by_iterator_incorrect_position():
    graph1 = create_sample_graph()
    iterator = graph1.bidirectional_iterator_for_traversing_edges()
    iterator.position = 10
    with pytest.raises(IncorrectPosition):
        graph1.remove_edge_by_iterator(iterator)
