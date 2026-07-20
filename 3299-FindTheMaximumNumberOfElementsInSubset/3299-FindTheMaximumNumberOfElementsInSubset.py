# Last updated: 20/07/2026, 11:25:27
class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        freq={}
        for v in nums:
            freq[v]=freq.get(v,0)+1
        ans=freq[1]-(freq[1]%2==0) if 1 in freq else 1
        m=max(nums)
        for i in list(freq.keys()):
            if i==1:
                continue
            x=i
            length=0
            while x<=m and freq.get(x,0)>=2:
                length+=2;x*=x
            length+=1 if freq.get(x,0) else -1
            ans=max(ans,length)
        return ans