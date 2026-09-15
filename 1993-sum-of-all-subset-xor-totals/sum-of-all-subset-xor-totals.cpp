class Solution {
public:
    int solve(vector<int>&nums,int i, int xr){
        if(i==nums.size()){
            return xr;
        }
        int a=solve(nums,i+1,xr);
        int b=solve(nums,i+1,xr^nums[i]);
        return a+b;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};