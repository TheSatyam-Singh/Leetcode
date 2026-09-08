class Solution {
public:
    int rob(vector<int>& nums) {
        int mx=0;
        int mx1=0;
        for(int i:nums){
            int curr=max(mx,mx1+i);
            mx1=mx;
            mx=curr;
        }
        return mx;
    }
};