# Last updated: 20/07/2026, 10:38:36
class Solution:
    def minArraySum(self,arr:list[int])->int:
        if not arr:
            return 0
        mx=max(arr)
        vis=[False]*(mx+1)
        for v in arr:
            vis[v]=True
        par=list(range(mx+1))
        vals=sorted(list(set(arr)))
        for x in vals:
            if par[x]!=x:
                continue
            for y in range(2*x,mx+1,x):
                if vis[y] and par[y]==y:
                    par[y]=x
        ans=0
        for v in arr:
            cur=v
            while par[cur]!=cur:
                cur=par[cur]
            ans+=cur
        return ans