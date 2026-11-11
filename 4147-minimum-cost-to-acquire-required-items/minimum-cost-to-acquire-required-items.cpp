class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long mn=min(need1, need2);
        long long mx=max(need1, need2);
        long long ans=need1*cost1+need2*cost2;
        ans=min(ans, mn*costBoth+(need1-mn)*cost1+(need2-mn)*cost2);
        ans=min(ans, mx*costBoth);
        return ans;
    }
};