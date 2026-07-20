// Last updated: 20/07/2026, 10:39:14
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1){
                a = i;
            }
            if (nums[i] == 2){
                b = i;
            }
            if (a != -1 && b != -1) {
                int d = a - b;
                if (d < 0){
                    d = -d;
                }
                if (d < ans){
                    ans = d;
                }
            }
        }
        if (ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};