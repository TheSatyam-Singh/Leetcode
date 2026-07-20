# Last updated: 20/07/2026, 10:40:07
class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return -1
        ans = -1
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] == nums[j]:
                    for k in range(j + 1, n):
                        if nums[j] == nums[k]:
                            d1 = j - i
                            d2 = k - j
                            d3 = k - i
                            total = d1 + d2 + d3
                            if ans == -1 or total < ans:
                                ans = total
        return ans