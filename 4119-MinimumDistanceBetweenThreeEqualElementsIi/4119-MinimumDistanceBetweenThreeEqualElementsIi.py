# Last updated: 20/07/2026, 10:40:11
class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        mp={}
        mini=float('inf')
        for i in range(len(nums)):
            num=nums[i]
            if num not in mp:
                mp[num]=[]
            mp[num].append(i)
            if len(mp[num])>3:
                mp[num].pop(0)
            if len(mp[num])==3:
                mini=min(mini,2*(mp[num][2]-mp[num][0]))
        if mini==float('inf'):
            return -1
        return mini