class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // Add original index
        vector<vector<int>> a(n, vector<int>(4));
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        // Sort by start time
        sort(a.begin(), a.end());
        vector<int> start(n);
        for (int i = 0; i < n; i++)
            start[i] = a[i][0];
        // dp[i][k] = maximum weight from i, taking at most k intervals
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        // ans[i][k] = indices used for dp[i][k]
        vector<vector<vector<int>>> ans(n + 1, vector<vector<int>>(5));
        for (int i = n - 1; i >= 0; i--) {
            // First interval starting after current interval ends
            int next = upper_bound(start.begin(), start.end(), a[i][1])
                       - start.begin();
            for (int k = 1; k <= 4; k++) {
                // Don't take current interval
                dp[i][k] = dp[i + 1][k];
                ans[i][k] = ans[i + 1][k];
                // Take current interval
                long long weight = a[i][2] + dp[next][k - 1];
                vector<int> temp = ans[next][k - 1];
                temp.push_back(a[i][3]);
                sort(temp.begin(), temp.end());
                // Take it if it gives better weight
                // or same weight with smaller indices
                if (weight > dp[i][k] ||
                    (weight == dp[i][k] && temp < ans[i][k])) {
                    dp[i][k] = weight;
                    ans[i][k] = temp;
                }
            }
        }
        return ans[0][4];
    }
};