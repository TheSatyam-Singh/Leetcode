# Last updated: 20/07/2026, 11:26:45
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_abs = 0
        min_abs = float('inf')
        negative_count = 0
        for row in matrix:
            for val in row:
                total_abs += abs(val)
                min_abs = min(min_abs, abs(val))
                if val < 0:
                    negative_count += 1
        if negative_count % 2 == 0:
            return total_abs
        else:
            return total_abs - 2 * min_abs