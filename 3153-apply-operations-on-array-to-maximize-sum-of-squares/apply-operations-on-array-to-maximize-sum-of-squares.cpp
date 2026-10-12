class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9+7;
        int cnt[30]={};
        for(int i:nums){
            for(int j=0;j<30;j++){
                cnt[j]+=i>>j&1;
            }
        }
        long long total=0;
        for(int i=0;i<k;i++){
            long long row=0;
            for(int j=0;j<30;j++){
                if(cnt[j]>i){
                    row|=1LL<<j;
                }
            }
            total=(total+row*row)%MOD;
        }
        return total;
    }
};