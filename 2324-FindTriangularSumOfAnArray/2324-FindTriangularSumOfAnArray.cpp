// Last updated: 20/07/2026, 11:26:11
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>ans;
        if (nums.size()==1){
            return nums[0];
        }
        for(int i=1;i<nums.size();i++){
            ans.push_back((nums[i]+nums[i-1])%10);
        }
        return triangularSum(ans);
    }
};