// Last updated: 20/07/2026, 10:39:21
class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        for(long long i=1000;i<=n;i*=1000){
            ans+=n-i+1;
        }
        return ans;
    }
};