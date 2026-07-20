// Last updated: 20/07/2026, 10:52:39
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return false;
            }
        }
        return nums[n]==n;
    }
};