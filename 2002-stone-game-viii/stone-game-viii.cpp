class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            ans[i]=nums[i]+ans[i-1];
        }
        int res=ans[n-1];
        for(int i=n-2;i>=1;i--){
            res=max(res,ans[i]-res);
        }
        return res;
    }
};