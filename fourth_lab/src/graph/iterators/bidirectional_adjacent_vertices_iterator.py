"""Файл bidirectional_adjacent_vertices_iterator.py для определения логики итератора по смежным вершинам."""

from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIncidentEdgesIterator
from src.graph.edge import Edge
from src.graph.vertex import Vertex
from typing import TypeVar, List, Dict, Self, Generic


T = TypeVar('T')


class BidirectionalAdjacentVerticesIterator(BidirectionalIncidentEdgesIterator[T], Generic[T]):
    """
    Двусторонний итератор для обхода вершин, смежных с данной вершиной.

    Attributes:
        _vertices (Dict[int, Vertex[T]]): Словарь вершин графа.
        _matrix (List[List[int]]): Матрица инцидентности.
        _edges (Dict[int, Edge]): Словарь рёбер.
        _order_edges (List[int]): Порядок рёбер.
        _order_vertex (List[int]): Порядок вершин.
        _vertex_id (int): ID вершины, для которой ищем смежные вершины.
        _current_edge (int): Текущая позиция в списке рёбер.
        _reverse (bool): Флаг обратного обхода.
    """
    __slots__ = ('_vertices',)

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 vertices: Dict[int, Vertex[T]], order_vertex: List[int],
                 vertex_id: int, reverse: bool = False) -> None:
        """
        Инициализирует итератор по смежным вершинам.

        Args:
            matrix (List[List[int]]): Матрица инцидентности графа.
            order_edges (List[int]): Упорядоченный список ID рёбер.
            edges (Dict[int, Edge]): Словарь рёбер графа.
            vertices (Dict[int, Vertex[T]]): Словарь вершин графа.
            order_vertex (List[int]): Упорядоченный список ID вершин.
            vertex_id (int): ID вершины, для которой ищем смежные.
            reverse (bool, optional): Флаг обратного обхода, изначально False.
        """
        super().__init__(matrix, order_edges, edges, order_vertex, vertex_id, reverse)
        self._vertices = vertices

    def __iter__(self) -> Self:
        """
        Возвращает итератор.

        Returns:
            Self: Этот же итератор.
        """
        return self

    def __next__(self) -> Vertex[T]:
        """
        Возвращает следующую смежную вершину и переходит на позицию вперёд.

        Returns:
            Vertex[T]: Следующая смежная вершина.

        Raises:
            StopIteration: Когда больше нет смежных вершин для итерации.
        """
        edge = super().__next__()
        v_from = edge.v_from
        v_to = edge.v_to
        res_v_id = v_from if v_to == self._vertex_id else v_to
        return self._vertices[res_v_id]

    def previous(self) -> Vertex[T]:
        """
        Возвращает предыдущую смежную вершину и переходит на позицию назад.

        Returns:
            Vertex[T]: Предыдущая смежная вершина.

        Raises:
            StopIteration: Когда нет предыдущих смежных вершин.
        """
        edge = super().previous()
        v_from = edge.v_from
        v_to = edge.v_to
        res_v_id = v_from if v_to == self._vertex_id else v_to
        return self._vertices[res_v_id]
