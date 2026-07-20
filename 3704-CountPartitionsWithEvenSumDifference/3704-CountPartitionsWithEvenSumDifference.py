# Last updated: 20/07/2026, 10:42:46
class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        total_sum = sum(nums)
        n = len(nums)
        count = 0
        left_sum = 0
        for i in range(n - 1):
            left_sum += nums[i]
            right_sum = total_sum - left_sum
            if (left_sum - right_sum) % 2 == 0:
                count += 1
        return count