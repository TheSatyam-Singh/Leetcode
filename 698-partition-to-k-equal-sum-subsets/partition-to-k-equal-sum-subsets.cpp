class Solution {
public:
    bool solve(vector<int>& nums, int k, int bs, int bn, int rs, int mask,
               vector<int>& dp) {
        if (bn == k) {
            return true;
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
        if (bs == rs) {
            return solve(nums, k, 0, bn + 1, rs, mask, dp);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (bs + nums[i] > rs) {
                continue;
            }
            if (mask & (1 << i)) {
                continue;
            }
            if (solve(nums, k, bs + nums[i], bn, rs, mask | (1 << i), dp)) {
                return dp[mask] = true;
            }
            // int a=nums[i];
            // nums[i]=0;
            // if(solve(nums,k,bs+a,bn,rs)){
            //     return true;
            // }
            // nums[i]=a;
        }
        return dp[mask] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        int rs = sum / k;
        if (sum % k != 0) {
            return false;
        }
        vector<int> dp(1 << nums.size(), -1);
        return solve(nums, k, 0, 0, rs, 0, dp);
    }
};