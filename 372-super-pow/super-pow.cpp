class Solution {
public:
    const int MOD=1337;
    int solve(long long a,int b){
        long long ans=1;
        while(b>0){
            if(b&1){
                ans=(ans*a)%MOD;
            }
            a=(a*a)%MOD;
            b/=2;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int ans=1;
        a%=MOD;
        for(int i:b){
            ans=(solve(ans,10)*solve(a,i))%MOD;
        }
        return ans;
    }
};