from src.graph.iterators.bidirectional_base_iterator import IBidirectionalBaseIterator
from src.graph.iterators.bidirectional_vertex_and_edge_iterator import BidirectionalVertexAndEdgeIterator
from src.graph.vertex import Vertex
from src.graph.edge import Edge
from typing import TypeVar, List, Self, Tuple, Union, Dict, Generic

T = TypeVar('T')


class ConstBidirectionalVertexAndEdgeIterator(BidirectionalVertexAndEdgeIterator[T], Generic[T]):
    __slots__ = ()

    def __init__(self, collection: Union[Dict[int, Vertex[T]], Dict[int, Edge]], order_list: List[int],
                 reverse: bool = False) -> None:
        object.__setattr__(self, '_collection', collection)
        object.__setattr__(self, '_order_list', order_list)
        object.__setattr__(self, '_position', 0 if not reverse else len(order_list) - 1)
        object.__setattr__(self, '_reverse', reverse)

    def __iter__(self) -> Self:
        return ConstBidirectionalVertexAndEdgeIterator[T](
            self._collection,
            self._order_list,
            reverse=self._reverse
        )

    def __setattr__(self, name: str, value) -> None:
        raise AttributeError(
            f"Constant iterator is protected, attribute '{name}' is changed."
        )
