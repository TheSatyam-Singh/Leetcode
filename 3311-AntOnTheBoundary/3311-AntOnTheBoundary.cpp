// Last updated: 20/07/2026, 11:25:25
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count=0;
        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+=nums[i];
            if(moves==0){
                count++;
            }
        }
        return count;
    }
};