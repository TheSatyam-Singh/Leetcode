// Last updated: 20/07/2026, 10:40:24
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int find=0;
            int ele=0;
            for (int j=i;j<nums.size();j++){
                ele++;
                if(nums[j]==target){
                    find++;
                }
                if(find>(ele/2)){
                    count++;
                }
            }
        }
        return count;
    }
};