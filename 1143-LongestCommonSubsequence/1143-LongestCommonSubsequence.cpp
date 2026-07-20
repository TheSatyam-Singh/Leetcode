// Last updated: 20/07/2026, 16:24:15
1class Solution {
2public:
3    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& dp){
4        if(i>=s1.size() || j>=s2.size()){
5            return 0;
6        }
7        if(dp[i][j]!=-1){
8            return dp[i][j];
9        }
10        else if(s1[i]==s2[j]){
11            return dp[i][j]=1+solve(i+1,j+1,s1,s2,dp);
12        }
13        else{
14            return dp[i][j]=max(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
15        }
16    }
17    int longestCommonSubsequence(string text1, string text2) {
18        int n=text1.size();
19        int m=text2.size();
20        vector<vector<int>>dp(n,vector<int>(m,-1));
21        return solve(0,0,text1,text2,dp);
22    }
23};