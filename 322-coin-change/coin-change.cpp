class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1);
       for(int i=0;i<=amount;i++){
           dp[i]=1e9;
       }
       dp[0]=0;
       for(int i=0;i<=amount;i++){
        for (int j=0;j<coins.size();j++){
            if (coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
       }
       if (dp[amount]==1e9){
        return -1;
       }
       return dp[amount];
    }
};