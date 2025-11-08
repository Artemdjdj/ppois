class BloomFilter:
    def __init__(self, number_of_hash_functions=5, size_of_bloom_filter=10000):
        self.__number_of_hash_functions = number_of_hash_functions
        self.__size_of_bloom_filter = size_of_bloom_filter
        self.__bloom_filter = [0] * self.__size_of_bloom_filter

    def __hash_djb2(self, s):
        start_hash = 5381
        for x in s:
            start_hash = start_hash * 33 + ord(x)
        return start_hash % self.__size_of_bloom_filter

    def __hash(self, item, number_of_hash_function):
        return self.__hash_djb2(str(item)+str(number_of_hash_function))

    def add_value(self, item):
        for number_of_hash_function in range(self.__number_of_hash_functions):
            result_index = self.__hash(item, number_of_hash_function)
            self.__bloom_filter[result_index] = 1

    def check_value(self, item):
        for number_of_hash_function in range(self.__number_of_hash_functions):
            result_index = self.__hash(item, number_of_hash_function)
            if self.__bloom_filter[result_index] == 0:
                return False
        return True

