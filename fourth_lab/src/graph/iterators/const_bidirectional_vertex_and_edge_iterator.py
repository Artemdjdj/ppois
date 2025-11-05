"""Файл const_bidirectional_vertex_and_edge_iterator.py для определения логики константного итератора по вершинам или ребрам"""

from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from src.graph.iterators.bidirectional_vertex_and_edge_iterator import BidirectionalVertexAndEdgeIterator
from src.graph.vertex import Vertex
from src.graph.edge import Edge
from typing import TypeVar, List, Self, Union, Dict, Generic

T = TypeVar('T')


class ConstBidirectionalVertexAndEdgeIterator(BidirectionalVertexAndEdgeIterator[T], Generic[T]):
    """
    Константный двусторонний итератор по вершинам или рёберам.
    
    Attributes:
        _collection (Union[Dict[int, Vertex[T]], Dict[int, Edge]]): Словарь вершин или рёбер.
        _order_list (List[int]): Упорядоченный список ID элементов.
        _position (int): Текущая позиция в order_list.
        _reverse (bool): Флаг обратного направления обхода.
    """
    __slots__ = ()

    def __init__(self, collection: Union[Dict[int, Vertex[T]], Dict[int, Edge]], order_list: List[int],
                 reverse: bool = False) -> None:
        """
        Инициализирует константный итератор по вершинам или рёбрам.

        Args:
            collection (Union[Dict[int, Vertex[T]], Dict[int, Edge]]): Словарь вершин или рёбер.
            order_list (List[int]): Упорядоченный список ID вершин или рёбер.
            reverse (bool, optional): Если True, начинать с конца, изначально False.
        """
        object.__setattr__(self, '_collection', collection)
        object.__setattr__(self, '_order_list', order_list)
        object.__setattr__(self, '_position', 0 if not reverse else len(order_list) - 1)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        """
        Возвращает новый константный итератор.

        Returns:
            Self: Новый экземпляр ConstBidirectionalVertexAndEdgeIterator
        """
        return ConstBidirectionalVertexAndEdgeIterator[T](
            self._collection,
            self._order_list,
            reverse=self._reverse
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
