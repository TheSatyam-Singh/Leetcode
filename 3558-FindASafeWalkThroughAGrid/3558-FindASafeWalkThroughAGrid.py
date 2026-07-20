# Last updated: 20/07/2026, 11:24:54
class Solution:
    def findSafeWalk(self,grid:List[List[int]],health:int)->bool:
        m=len(grid)
        n=len(grid[0])
        dis=[]
        for i in range(m):
            row=[]
            for j in range(n):
                row.append(float("inf"))
            dis.append(row)
        q=[(0,0)]
        dis[0][0]=grid[0][0]
        while q:
            x,y=q.pop(0)
            if x==m-1 and y==n-1:
                return True
            directions=[[0,1],[0,-1],[1,0],[-1,0]]
            for d in directions:
                nx=x+d[0]
                ny=y+d[1]
                if nx<0 or nx>=m or ny<0 or ny>=n:
                    continue
                cost=dis[x][y]+grid[nx][ny]
                if cost>=health:
                    continue
                if cost<dis[nx][ny]:
                    dis[nx][ny]=cost
                    if grid[nx][ny]==0:
                        q.insert(0,(nx,ny))
                    else:
                        q.append((nx,ny))
        return False