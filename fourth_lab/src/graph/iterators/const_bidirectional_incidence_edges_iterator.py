"""Файл const_bidirectional_incidence_edges_iterator.py для определения логики константного итератора по инцидентным ребрам"""

from src.graph.iterators.bidirectional_incidence_edges_iterator import BidirectionalIncidentEdgesIterator
from src.graph.edge import Edge
from typing import List, Self, TypeVar, Generic, Dict

T = TypeVar('T')


class ConstBidirectionalIncidentEdgesIterator(BidirectionalIncidentEdgesIterator[T], Generic[T]):
    """
    Константный двусторонний итератор по инцидентным рёбрам.

    Attributes:
        _matrix (List[List[int]]): Матрица инцидентности графа.
        _edges (Dict[int, Edge]): Словарь рёбер графа.
        _order_edges (List[int]): Упорядоченный список ID рёбер.
        _order_vertex (List[int]): Упорядоченный список ID вершин.
        _vertex_id (int): ID вершины, для которой ищем инцидентные рёбра.
        _vertex (int): Индекс вершины в матрице инцидентности.
        _current_edge (int): Текущая позиция в списке рёбер.
        _reverse (bool): Флаг обратного направления обхода.
    """
    __slots__ = ()

    def __init__(self, matrix: List[List[int]], order_edges: List[int], edges: Dict[int, Edge],
                 order_vertex: List[int], vertex_id: int, reverse: bool = False) -> None:
        """
        Инициализирует константный итератор по инцидентным рёбрам.

        Args:
            matrix (List[List[int]]): Матрица инцидентности графа.
            order_edges (List[int]): Упорядоченный список ID рёбер (порядок столбцов).
            edges (Dict[int, Edge]): Словарь рёбер графа.
            order_vertex (List[int]): Упорядоченный список ID вершин (порядок строк).
            vertex_id (int): ID вершины, для которой ищем инцидентные рёбра.
            reverse (bool, optional): Флаг обратного обхода, изначально False.
        """
        object.__setattr__(self, '_matrix', matrix)
        object.__setattr__(self, '_order_edges', order_edges)
        object.__setattr__(self, '_edges', edges)
        object.__setattr__(self, '_order_vertex', order_vertex)
        object.__setattr__(self, '_vertex_id', vertex_id)
        object.__setattr__(self, '_vertex', order_vertex.index(vertex_id))
        object.__setattr__(self, '_current_edge', len(matrix[0]) - 1 if reverse else 0)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        """
        Возвращает новый константный итератор с тем же состоянием.

        Returns:
            Self: Новый экземпляр ConstBidirectionalIncidentEdgesIterator
        """
        return ConstBidirectionalIncidentEdgesIterator[T](
            self._matrix,
            self._order_edges,
            self._edges,
            self._order_vertex,
            self._vertex_id,
            self._reverse
        )

    def __setattr__(self, name: str, value) -> None:
        """
        Переопределённый метод присваивания атрибутов.

        Args:
            name (str): Имя атрибута, который пытаются изменить.
            value: Значение.

        Raises:
            AttributeError: Всегда выбрасывает исключение с описанием попытки изменения,
                          включая имя атрибута.
        """
        raise AttributeError(
            f"Constant iterator is protected, attribute '{name}' is changed."
        )
