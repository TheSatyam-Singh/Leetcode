# Last updated: 20/07/2026, 10:38:20
from functools import cache
class Solution:
    def goodIntegers(self, l: int, r: int, k: int) -> int:
        def solve(x):
            s=str(x)
            @cache
            def dfs(i,pre,started,tight):
                if i==len(s):
                    return 1
                lim=int(s[i]) if tight else 9
                ans=0
                for d in range(lim+1):
                    nt=tight and d==lim
                    if not started:
                        ans+=dfs(i+1,d,d!=0,nt)
                    elif abs(d-pre)<=k:
                        ans+=dfs(i+1,d,True,nt)
                return ans
            return dfs(0,0,False,True)
        return solve(r)-solve(l-1)