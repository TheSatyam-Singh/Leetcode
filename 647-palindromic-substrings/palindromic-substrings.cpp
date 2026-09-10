class Solution {
public:
    int solve(string s,int l, int r,vector<vector<int>> &dp){
        if(l>=r){
            return true;
        }
        if (dp[l][r]!=-1) {
            return dp[l][r];
        }
        if (s[l]!=s[r]) {
            return dp[l][r]=false;
        }
        return dp[l][r]=solve(s,l+1,r-1,dp);
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)){
                    ans++;
                }
            }
        }
        return ans;
    }

    // ---------recursion--------------
    // int solve(string s,int l, int r){
    //     if(l>=r){
    //         return true;
    //     }
    //     if(s[l]!=s[r]){
    //         return false;
    //     }
    //     return solve(s,l+1,r-1);
    // }
    // int countSubstrings(string s) {
    //     int n=s.size();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(solve(s,i,j)){
    //                 ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // ----------brute force----------
    // int countSubstrings(string s) {
    //     int n = s.size();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             int l=i;
    //             int r=j;
    //             bool palin=true;
    //             while(l<r){
    //                 if(s[l]!=s[r]){
    //                     palin=false;
    //                     break;
    //                 }
    //                 l++;
    //                 r--;
    //             }
    //             if(palin){
    //                 ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};