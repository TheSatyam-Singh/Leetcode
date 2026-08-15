class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=0;
        bool zeroyes=false;
        for(int i:nums){
            total^=i;
            if(i!=0){
                zeroyes=true;
            }
        }
        if(total!=0){
            return nums.size();
        }
        if(!zeroyes){
            return 0;
        }
        return nums.size()-1;
    }
};