from typing import List

class Counter:
    @staticmethod
    def count_number_in_list(arr: List[int], number: int) -> int:
        count = 0
        for el in arr:
            if el == number:
                count += 1
        return count

    @staticmethod
    def count_elements_in_list(arr: List[int], element: int) -> List[int]:
        res_arr = []
        for i, el in enumerate(arr):
            if el == element:
                res_arr.append(i)
        return res_arr


