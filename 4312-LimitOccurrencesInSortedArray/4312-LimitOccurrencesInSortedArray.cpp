// Last updated: 20/07/2026, 10:38:19
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n=0;
        for(int i:nums){
            if(n<k || i!=nums[n-k]){
                nums[n]=i;
                n+=1;
            }
        }
        nums.resize(n);
        return nums;
    }
};