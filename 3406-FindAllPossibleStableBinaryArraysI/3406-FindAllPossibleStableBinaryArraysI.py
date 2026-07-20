# Last updated: 20/07/2026, 11:25:12
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        MOD = 1000000007
        dp = []

        for i in range(zero + 1):
            row = []
            for j in range(one + 1):
                row.append([0, 0])
            dp.append(row)

        for i in range(1, min(limit, zero) + 1):
            dp[i][0][0] = 1

        for j in range(1, min(limit, one) + 1):
            dp[0][j][1] = 1

        for i in range(zero + 1):
            for j in range(one + 1):

                if i > 0:
                    for k in range(1, limit + 1):
                        if i - k >= 0:
                            dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD
                        else:
                            break
                if j > 0:
                    for k in range(1, limit + 1):
                        if j - k >= 0:
                            dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD
                        else:
                            break

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD