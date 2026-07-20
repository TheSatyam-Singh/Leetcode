# Last updated: 20/07/2026, 10:52:49
class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        ans=[]
        for i in range(len(grid[0])):
            size=0
            for j in range(len(grid)):
                size=max(size,len(str(grid[j][i])))
            ans.append(size)
        return ans