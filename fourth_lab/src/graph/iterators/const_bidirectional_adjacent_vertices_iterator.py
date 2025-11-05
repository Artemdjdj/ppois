"""Файл const_bidirectional_adjacent_vertices_iterator.py для определения логики константного итератора по смежным вершинам."""

from src.graph.iterators.bidirectional_adjacent_vertices_iterator import BidirectionalAdjacentVerticesIterator
from src.graph.edge import Edge
from typing import List, Dict, Self, Generic, TypeVar
from src.graph.vertex import Vertex

T = TypeVar('T')


class ConstBidirectionalAdjacentVerticesIterator(BidirectionalAdjacentVerticesIterator[T], Generic[T]):
    """
    Константный двусторонний итератор для смежных вершин.

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
    __slots__ = ()

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 vertices: Dict[int, Vertex[T]], order_vertex: List[int],
                 vertex_id: int, reverse: bool = False) -> None:
        """
        Инициализирует константный итератор по смежным вершинам.

        Args:
            matrix (List[List[int]]): Матрица инцидентности графа.
            order_edges (List[int]): Упорядоченный список ID рёбер.
            edges (Dict[int, Edge]): Словарь рёбер графа.
            vertices (Dict[int, Vertex[T]]): Словарь вершин графа.
            order_vertex (List[int]): Упорядоченный список ID вершин.
            vertex_id (int): ID вершины.
            reverse (bool): Флаг обратного обхода, изначально False.
        """
        object.__setattr__(self, '_matrix', matrix)
        object.__setattr__(self, '_order_edges', order_edges)
        object.__setattr__(self, '_edges', edges)
        object.__setattr__(self, '_vertices', vertices)
        object.__setattr__(self, '_order_vertex', order_vertex)
        object.__setattr__(self, '_vertex_id', vertex_id)
        object.__setattr__(self, '_vertex', order_vertex.index(vertex_id))
        object.__setattr__(self, '_current_edge', len(matrix[0]) - 1 if reverse else 0)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        """
        Возвращает новый константный итератор с тем же состоянием.

        Returns:
            Self: Новый экземпляр ConstBidirectionalAdjacentVerticesIterator
        """
        return ConstBidirectionalAdjacentVerticesIterator[T](
            self._matrix,
            self._order_edges,
            self._edges,
            self._vertices,
            self._order_vertex,
            self._vertex_id,
            self._reverse
        )

    def __setattr__(self, name: str, value) -> None:
        """
        Переопределённый метод присваивания атрибутов.

        Args:
            name (str): Имя атрибута.
            value: Значение.

        Raises:
            AttributeError: Всегда выбрасывает исключение с описанием попытки изменения,
                          включая имя атрибута.
        """
        raise AttributeError(
            f"Constant iterator is protected, attribute '{name}' is changed."
        )
