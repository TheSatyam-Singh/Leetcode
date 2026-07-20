# Last updated: 20/07/2026, 10:42:24
class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        for i in grid:
            total = total + sum(i)
        if total % 2 != 0:
            return False

        half = total // 2
        csum = 0
        for i in grid:
            csum = csum + sum(i)
            if csum == half:
                return True
        
        csum = 0
        col = len(grid[0])
        for i in range(col):
            colsum = 0
            for j in grid:
                colsum = colsum + j[i]
            csum = csum + colsum
            if csum == half:
                return True
        return False