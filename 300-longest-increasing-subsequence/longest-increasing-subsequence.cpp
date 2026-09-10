class Solution {
public:
    // int solve(vector<int>&nums, int idx,int prev,vector<vector<int>>& dp){
    //     if(idx>=nums.size()){
    //         return 0;
    //     }
    //     if (dp[idx][prev + 1] != -1) {
    //         return dp[idx][prev + 1];
    //     }

    //     int ntake=solve(nums,idx+1,prev,dp);
    //     int take=0;
    //     if(prev==-1 || nums[idx]>nums[prev]){
    //         take=1+solve(nums,idx+1,idx,dp);
    //     }
    //     return dp[idx][prev + 1] = max(take, ntake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     return solve(nums,0,-1,dp);
    // }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(int i:nums){
            auto it=lower_bound(ans.begin(),ans.end(),i);
            if(it==ans.end()){
                ans.push_back(i);
            }else{
                *it=i;
            }
        }
        return ans.size();
    }
};