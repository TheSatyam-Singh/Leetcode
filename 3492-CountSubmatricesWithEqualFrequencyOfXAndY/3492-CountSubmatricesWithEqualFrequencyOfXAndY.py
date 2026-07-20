# Last updated: 20/07/2026, 11:24:59
class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        row = len(grid)
        col = len(grid[0])
        sumx = [0] * col
        sumy = [0] * col
        ans = 0
        for i in range(row):
            resx = 0
            resy = 0
            for j in range(col):
                if grid[i][j] == 'X':
                    resx += 1
                elif grid[i][j] == 'Y':
                    resy += 1
                sumx[j] += resx
                sumy[j] += resy
                if sumx[j] > 0 and sumx[j] == sumy[j]:
                    ans += 1
        return ans