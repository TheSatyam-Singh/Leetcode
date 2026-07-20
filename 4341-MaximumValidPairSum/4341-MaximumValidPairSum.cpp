// Last updated: 20/07/2026, 10:38:07
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        if(nums.size()<k+1){
            return -1;
        }
        int tmax=INT_MIN;
        int valmax=INT_MIN;
        for(int j=k;j<nums.size();j++){
            valmax=max(valmax,nums[j-k]);
            tmax=max(tmax,valmax+nums[j]);
        }
        return tmax;
    }
};