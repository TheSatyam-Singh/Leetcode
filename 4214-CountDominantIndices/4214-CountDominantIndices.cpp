// Last updated: 20/07/2026, 10:39:35
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size(),res=0;
        vector<long long> suffixSum(n+1,0);
        for (int i =n-1;i>=0;--i){
            suffixSum[i]=suffixSum[i+1]+nums[i];
        }
        for (int i =0;i<n-1;++i){
            double avg=(double)suffixSum[i+1]/(n-i-1);
            if (nums[i]>avg){
                res++;
            }
        }
        return res;
    }
};