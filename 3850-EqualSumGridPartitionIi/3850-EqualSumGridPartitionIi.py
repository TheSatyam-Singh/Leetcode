# Last updated: 20/07/2026, 10:42:32
class Solution:
    def canPartitionGrid(self, grid):
        total_sum = 0
        for row in grid:
            total_sum += sum(row)

        def check(grid):
            top_sum = 0
            seen = set()
            rows = len(grid)
            cols = len(grid[0])
            for i in range(rows):
                row = grid[i]
                row_sum = sum(row)
                top_sum += row_sum
                bottom_sum = total_sum - top_sum
                for val in row:
                    seen.add(val)
                diff = top_sum - bottom_sum
                if diff == 0:
                    return True
                if diff == grid[0][0] or diff == grid[0][-1] or diff == row[0]:
                    return True
                if cols > 1 and i > 0:
                    if diff in seen:
                        return True
            return False
            
        def transpose(grid):
            transposed = []
            cols = len(grid[0])
            rows = len(grid)
            for j in range(cols):
                new_row = []
                for i in range(rows):
                    new_row.append(grid[i][j])
                transposed.append(new_row)
            return transposed
        if check(grid):
            return True
        if check(grid[::-1]):
            return True
        transposed_grid = transpose(grid)
        if check(transposed_grid):
            return True
        if check(transposed_grid[::-1]):
            return True
        return False
