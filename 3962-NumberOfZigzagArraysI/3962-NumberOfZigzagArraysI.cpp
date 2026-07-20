// Last updated: 20/07/2026, 11:24:24
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD=1000000007;
        int sum=r-l+1;
        vector<int>dp(sum,1);
        for(int i=2;i<=n;i++){
            reverse(dp.begin(),dp.end());
            long long psum=0;
            for(int j=0;j<sum;j++){
                int old=dp[j];
                dp[j]=psum;
                psum=(psum+old)%MOD;
            }
        }
        long long ans=0;
        for(int i:dp){
            ans=(ans+i)%MOD;
        }
        return (ans*2)%MOD;
    }
};