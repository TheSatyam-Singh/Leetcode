// Last updated: 20/07/2026, 11:24:34
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> nums;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        nums.push_back(grid[x][y]);
                    }
                }
                sort(nums.begin(), nums.end());
                int minDiff = INT_MAX;
                for (int t = 1; t < nums.size(); t++) {
                    if (nums[t] != nums[t - 1]) {
                        int diff = nums[t] - nums[t - 1];
                        if (diff < minDiff) {
                            minDiff = diff;
                        }
                    }
                }
                if (minDiff == INT_MAX) {
                    minDiff = 0;
                }
                ans[i][j] = minDiff;
            }
        }
        return ans;
    }
};