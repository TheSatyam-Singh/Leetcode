class Solution:
    def maxProduct(self, n: int) -> int:
        num_str = str(n)
        largest = -1
        second_largest = -1
        for char in num_str:
            digit = int(char)
            if digit > largest:
                second_largest = largest
                largest = digit
            elif digit > second_largest:
                second_largest = digit
        return largest * second_largest
