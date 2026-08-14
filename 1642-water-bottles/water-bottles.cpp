class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=(numBottles-1)/(numExchange-1);
        int ans=numBottles+sum;
        return ans;
    }
};