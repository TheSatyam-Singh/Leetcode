class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=n+1;
        int sum=0;
        int a=0;
        vector<int>dp(n+1,n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>target){
                sum-=nums[a];
                a++;
            }
            dp[i+1]=dp[i];
            if(sum==target){
                ans=min(ans,i-a+1+dp[a]);
                dp[i+1]=min(dp[i],i-a+1);
            }
        }
        if(ans==n+1){
            return -1;
        }
        return ans;
    }
};