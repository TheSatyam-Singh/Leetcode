class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j+i-1<n;j++){
                int k=j+i-1;
                if(s[j]==s[k]){
                    dp[j][k]=dp[j+1][k-1]+2;
                }else{
                    dp[j][k]=max(dp[j+1][k],dp[j][k-1]);
                }
            }
        }
        return dp[0][n-1];
        // unordered_map<char,int>mp;
        // for(char i:s){
        //     mp[i]++;
        // }
        // vector<int>ans;
        // for(auto it:mp){
        //     ans.push_back(it.second);
        // }
        // return *max_element(ans.begin(),ans.end());
    }
};