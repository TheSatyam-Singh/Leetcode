// Last updated: 20/07/2026, 11:25:02
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]%3==0){
                continue;
            } else{
                count++;
            }
        }
        return count;
    }
};