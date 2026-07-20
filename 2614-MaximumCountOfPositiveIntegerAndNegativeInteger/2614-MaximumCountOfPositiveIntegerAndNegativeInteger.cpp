// Last updated: 20/07/2026, 11:25:54
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pcount=0;
        int ncount=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i]>0){
                pcount++;
            }
            if (nums[i]<0){
                ncount++;
            }
        }
        return max(pcount,ncount);
    }
};