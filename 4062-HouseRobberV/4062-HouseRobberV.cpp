// Last updated: 20/07/2026, 10:40:27
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<long long> dp(n,0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1];
            long long take = nums[i];
            if(i-1 >= 0 && colors[i] == colors[i-1]){
                if(i-2 >= 0) take += dp[i-2];
                else take += 0;
            }else{
                take += dp[i-1];
            }
            dp[i] = max(dp[i], take);
        }
        return dp[n-1];
    }
};