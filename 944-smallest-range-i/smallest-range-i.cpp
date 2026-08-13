class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            mx--;
            mn++;
            if(mn>mx || mx==mn){
                return 0;
            }
        }
        return mx-mn;
    }
};