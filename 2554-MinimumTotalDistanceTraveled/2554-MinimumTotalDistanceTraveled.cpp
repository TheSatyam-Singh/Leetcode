// Last updated: 20/07/2026, 11:25:59
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factoryPositions;
        for (auto &f : factory) {
            for (int i = 0; i < f[1]; i++) {
                factoryPositions.push_back(f[0]);
            }
        }
        int n = robot.size();
        int m = factoryPositions.size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return solve(0, 0, robot, factoryPositions, dp);
    }
    long long solve(int i, int j, vector<int>& robot, vector<int>& factory, vector<vector<long long>>& dp) {
        if (i == robot.size()) return 0;
        if (j == factory.size()) return 1e12;
        if (dp[i][j] != -1) return dp[i][j];
        long long take = abs(robot[i] - factory[j]) + solve(i + 1, j + 1, robot, factory, dp);
        long long skip = solve(i, j + 1, robot, factory, dp);
        return dp[i][j] = min(take, skip);
    }
};