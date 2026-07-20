// Last updated: 20/07/2026, 10:37:53
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mxrange=-1;
        int tsum=0;
        for(int i:nums){
            string s=to_string(abs(i));
            auto[min_it,max_it]=minmax_element(s.begin(),s.end());
            int currrange=*max_it-*min_it;
            if(currrange>mxrange){
                mxrange=currrange;
                tsum=i;
            }else if(currrange==mxrange){
                tsum+=i;
            }
        }
        return tsum;
    }
};