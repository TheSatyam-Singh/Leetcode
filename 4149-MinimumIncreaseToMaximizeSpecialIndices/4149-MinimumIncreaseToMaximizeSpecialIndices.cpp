// Last updated: 20/07/2026, 10:39:51
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<long long> need(n, 0);
        
        for (int i = 1; i < n - 1; i++) {
            int m = max(nums[i-1], nums[i+1]);
            if (nums[i] <= m)
                need[i] = m + 1 - nums[i];
        }
        
        vector<pair<int, long long>> dp(n, {0, 0});
        
        for (int i = 1; i < n - 1; i++) {
            pair<int, long long> skip = dp[i-1];
            pair<int, long long> take = (i >= 2) ? dp[i-2] : make_pair(0, 0LL);
            take.first++;
            take.second += need[i];
            
            if (take.first > skip.first || (take.first == skip.first && take.second < skip.second))
                dp[i] = take;
            else
                dp[i] = skip;
        }
        
        return dp[n-2].second;
    }
};