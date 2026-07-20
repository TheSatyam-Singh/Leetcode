// Last updated: 20/07/2026, 11:29:10
class Solution {
public:
    using p = pair<int,int>;
    vector<vector<int>> dp;
    int countWalls(vector<int> &walls , int l , int r)
    {
        int left = lower_bound(walls.begin() , walls.end(),l) - walls.begin();
        int right = upper_bound(walls.begin() , walls.end() , r) - walls.begin();
        return right - left;
    }
    int solve(vector<int> &walls , vector<p> &roboDist , vector<p>&range , int ind , int prevDir)
    {
        if(ind == roboDist.size()) return 0;
        if(dp[ind][prevDir] != -1) return dp[ind][prevDir];
        int leftStart = range[ind].first;
        if(prevDir == 1)
        {
            leftStart = max(leftStart , range[ind-1].second + 1);
        }
        int leftTake = countWalls(walls , leftStart , roboDist[ind].first) + solve(walls , roboDist , range , ind+1, 0);

        int rightTake = countWalls(walls , roboDist[ind].first , range[ind].second) + solve(walls,roboDist , range , ind+1,1);
        return dp[ind][prevDir] =  max(leftTake , rightTake);
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) 
    {
        int n = robots.size();
        vector<p> roboDist(n);
        for(int i=0;i<n;i++)
        {
            roboDist[i] = {robots[i] , distance[i]};
        }
        sort(roboDist.begin() , roboDist.end());
        sort(walls.begin() , walls.end());
        vector<p> range(n);
        for(int i=0;i<n;i++)
        {
            auto [pos , dist] = roboDist[i];
            int leftLimit = (i==0) ? 1 : roboDist[i-1].first + 1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first - 1;
            int L = max(pos-dist , leftLimit);
            int R = min(pos+dist , rightLimit);
            range[i] = {L,R};
        }
        dp.assign(n+1,vector<int>(2,-1)); 
        return solve(walls , roboDist , range , 0,0);
    }
};