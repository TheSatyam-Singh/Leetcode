// Last updated: 20/07/2026, 10:40:13
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        const int MAX_XOR = 1 << 15;
        vector<int> dp(MAX_XOR, -1);
        dp[0] = 0;
        
        for (int num : nums) {
            vector<int> next_dp = dp;
            for (int x = 0; x < MAX_XOR; ++x) {
                if (dp[x] != -1) {
                    int new_xor = x ^ num;
                    next_dp[new_xor] = max(next_dp[new_xor], dp[x] + 1);
                }
            }
            dp = next_dp;
        }
        
        if (dp[target] == -1) {
            return -1;
        }
        
        return n - dp[target];
    }
};