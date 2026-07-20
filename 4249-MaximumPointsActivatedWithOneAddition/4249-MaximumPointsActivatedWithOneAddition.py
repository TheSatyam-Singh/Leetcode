# Last updated: 20/07/2026, 10:39:19
class Solution:
    def maxActivated(self, points: list[list[int]]) -> int:
        p = {}

        def f(i):
            if i not in p:
                return i
            if p[i] != i:
                p[i] = f(p[i])
            return p[i]

        for x, y in points:
            p[f(x)] = f(y + (1 << 31))
        count = Counter(f(x) for x, y in points)
        return sum(nlargest(2, count.values())) + 1
        