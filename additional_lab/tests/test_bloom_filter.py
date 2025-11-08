import pytest
from src.bloom_filter import BloomFilter


def create_sample_bloom_filter() -> BloomFilter:
    bf = BloomFilter()
    bf.add_value("hello")
    bf.add_value("world")
    bf.add_value("0")
    bf.add_value("1")
    bf.add_value("a")
    bf.add_value("b sdf dsd")
    return bf


def test_check_is_value_not_in_bloom_filter():
    bf = create_sample_bloom_filter()
    assert bf.check_value("hello") == True
    assert bf.check_value("wor") == False
    assert bf.check_value("0") == True
