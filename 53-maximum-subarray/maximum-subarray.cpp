class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count=nums[0];
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            count=max(nums[i],count+nums[i]);
            mx=max(mx,count);
        }
        return mx;
    }
};