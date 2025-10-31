import pytest
from src.sorting.sorting import GnomeSorting, PigeonholeSorting
from src.sorting.user import User

test_data1 = [
    ([1, 3, 2], [1, 2, 3]),
    ([8, 5, 6, 7, 1, 2, 3, -7, 98, 24], [-7, 1, 2, 3, 5, 6, 7, 8, 24, 98]),
    ([8.0, 5.5, 6.9, 1.7, 1, 2, 3.7, -7.0, 98.0, 24.0], [-7.0, 1, 1.7, 2, 3.7, 5.5, 6.9, 8.0, 24.0, 98.0]),
    ([], []),
    (["cucumbers", "apple", "bananas", "tomatoes", "legend", "template"],
     ["apple", "bananas", "cucumbers", "legend", "template", "tomatoes"]),
    (["b", "c", "d", "e", "b", "s", "a"], ["a", "b", "b", "c", "d", "e", "s"]),
    ([User("alice", "Alice", 20, 43242), User("bob", "Bob", 37, 2432), User("artem", "Artem", 18, 1111)],
     [User("alice", "Alice", 20, 43242), User("artem", "Artem", 18, 1111), User("bob", "Bob", 37, 2432)]),
    ([User("art", "Alice", 20, 43242), User("art", "Bob", 37, 2432), User("art", "Artem", 18, 1111)],
     [User("art", "Alice", 20, 43242), User("art", "Artem", 18, 1111), User("art", "Bob", 37, 2432)]),
    ([User("art", "Art", 20, 43242), User("art", "Art", 37, 2432), User("art", "Art", 18, 1111)],
     [User("art", "Art", 18, 1111), User("art", "Art", 20, 43242), User("art", "Art", 37, 2432)]),
    ([User("art", "Art", 11, 43242), User("art", "Art", 11, 2432), User("art", "Art", 11, 1111)],
     [User("art", "Art", 11, 1111), User("art", "Art", 11, 2432), User("art", "Art", 11, 43242)]),
]

test_data2 = [
    ([1, 3, 2], [1, 2, 3]),
    ([8, 5, 6, 7, 1, 2, 3, -7, 98, 24], [-7, 1, 2, 3, 5, 6, 7, 8, 24, 98]),
]

test_data3 = [
    (
        [User("art", "Art", 20, 43242), User("art", "Art", 37, 2432), User("art", "Art", 18, 1111)],
        lambda x: x.age,
        [User("art", "Art", 18, 1111), User("art", "Art", 20, 43242), User("art", "Art", 37, 2432)]
    ),
    (
        [User("art", "Art", 20, 43242), User("art", "Art", 37, 2432), User("art", "Art", 18, 1111)],
        lambda x: x.id,
        [User("art", "Art", 18, 1111), User("art", "Art", 37, 2432), User("art", "Art", 20, 43242)]
    ),
]


@pytest.mark.parametrize("array, result_array", test_data1)
def test_gnome_sorting(array, result_array):
    assert GnomeSorting().sort(array) == result_array


@pytest.mark.parametrize("array, result_array", test_data1)
def test_gnome_sorting_reverse(array, result_array):
    reversed_result_array = result_array[::-1]
    assert GnomeSorting().sort(array, reverse=True) == reversed_result_array


@pytest.mark.parametrize("array, result_array", test_data2)
def test_pigeonhole_sorting(array, result_array):
    assert PigeonholeSorting().sort(array) == result_array


@pytest.mark.parametrize("array, result_array", test_data2)
def test_pigeonhole_sorting_reverse(array, result_array):
    reversed_result_array = result_array[::-1]
    assert PigeonholeSorting().sort(array, reverse=True) == reversed_result_array


@pytest.mark.parametrize("array, key_func, result_array", test_data3)
def test_pigeonhole_sorting_user(array, key_func, result_array):
    assert PigeonholeSorting().sort(array, key_func) == result_array


@pytest.mark.parametrize("array, key_func, result_array", test_data3)
def test_pigeonhole_sorting_user_reverse(array, key_func, result_array):
    reversed_result_array = result_array[::-1]
    assert PigeonholeSorting().sort(array, key_func, reverse=True) == reversed_result_array


@pytest.mark.parametrize(
    "array",
    [
        [8.0, 5.5, 6.9, 1.7, 1, 2, 3.7, -7.0, 98.0, 24.0],
    ])
def test_pigeonhole_sorting_incorrect_input_type_error(array):
    with pytest.raises(TypeError):
        PigeonholeSorting().sort(array)


@pytest.mark.parametrize(
    "array",
    [
        [],
        ["cucumbers", "apple", "bananas", "tomatoes", "legend", "template"],
        ["b", "c", "d", "e", "b", "s", "a"]
    ])
def test_pigeonhole_sorting_incorrect_input_exception(array):
    with pytest.raises(Exception):
        PigeonholeSorting().sort(array)


@pytest.mark.parametrize(
    "array, key_func",
    [
        (
                [User("alice", "Alice", 20, 43242), User("bob", "Bob", 37, 2432), User("artem", "Artem", 18, 1111)],
                lambda x: x.username
        ),
        (
                [User("alice", "Alice", 20, 43242), User("bob", "Bob", 37, 2432), User("artem", "Artem", 18, 1111)],
                lambda x: x.name
        ),
    ]
)
def test_pigeonhole_sorting_incorrect_input_exception_func(array, key_func):
    with pytest.raises(Exception):
        PigeonholeSorting().sort(array, key_func)
