// Last updated: 20/07/2026, 10:39:57
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>ans;
        const long long MOD=1000000007;
        int n=s.size();
        vector<long long>prefixNum(n+1,0);
        vector<long long>prefixSum(n+1,0);
        vector<int>prefixCnt(n+1,0);
        vector<long long>pow10(n+1,1);
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%MOD;
        }
        for(int i=0;i<n;i++){
            prefixNum[i+1]=prefixNum[i];
            prefixSum[i+1]=prefixSum[i];
            prefixCnt[i+1]=prefixCnt[i];
            if(s[i]!='0'){
                int digit=s[i]-'0';
                prefixSum[i+1]+=digit;
                prefixNum[i+1]=(prefixNum[i]*10+digit)%MOD;
                prefixCnt[i+1]++;
            }
        }
        for(int i=0;i<queries.size();i++){
            long long sum=0;
            long long num=0;
            int l=queries[i][0];
            int r=queries[i][1];
            sum=prefixSum[r+1]-prefixSum[l];
            int digits=prefixCnt[r+1]-prefixCnt[l];
            num=(prefixNum[r+1]-(prefixNum[l]*pow10[digits])%MOD+MOD)%MOD;
            ans.push_back((sum*num)%MOD);
        }
        return ans;
    }
};