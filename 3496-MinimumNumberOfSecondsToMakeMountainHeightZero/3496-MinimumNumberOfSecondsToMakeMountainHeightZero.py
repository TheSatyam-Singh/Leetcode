# Last updated: 20/07/2026, 11:24:58
class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        left = 1
        right = min(workerTimes) * mountainHeight * (mountainHeight + 1) // 2
        while left < right:
            mid = (left + right) // 2
            total = 0
            for i in workerTimes:
                k = int((math.sqrt(1 + 8 * mid / i) - 1) // 2)
                total += k
                if total >= mountainHeight:
                    break
            if total >= mountainHeight:
                right = mid
            else:
                left = mid + 1
        return left