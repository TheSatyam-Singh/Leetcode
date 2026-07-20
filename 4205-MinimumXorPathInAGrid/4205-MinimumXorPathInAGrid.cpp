// Last updated: 20/07/2026, 10:39:44
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        dp[0][0].insert(grid[0][0]);
        for (int j = 1; j < n; j++) {
            for (int x : dp[0][j - 1]) {
                dp[0][j].insert(x ^ grid[0][j]);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int x : dp[i - 1][0]) {
                dp[i][0].insert(x ^ grid[i][0]);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int x : dp[i - 1][j]) {
                    dp[i][j].insert(x ^ grid[i][j]);
                }
                for (int x : dp[i][j - 1]) {
                    dp[i][j].insert(x ^ grid[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int x : dp[m - 1][n - 1]) {
            ans = min(ans, x);
        }
        return ans;
    }
};