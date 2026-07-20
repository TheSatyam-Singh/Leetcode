# Last updated: 20/07/2026, 10:38:04
class Solution:
    def isMiddleElementUnique(self, nums: list[int]) -> bool:
        s=len(nums)//2
        count=0
        find=nums[s]
        for i in nums:
            if find == i:
                count+=1

        if count<2:
            return True
        else:
            return False
        