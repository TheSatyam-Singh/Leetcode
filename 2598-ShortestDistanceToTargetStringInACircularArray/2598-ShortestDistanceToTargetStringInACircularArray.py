# Last updated: 20/07/2026, 11:25:56
class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        i=startIndex
        n=len(words)
        ans=[]
        while i<=(n+startIndex-1) :
            if target==words[i%n] :
                ans.append(abs(i-startIndex))
                ans.append(n-abs(i-startIndex))
            i+=1
        if ans :
            return min(ans)
        return -1