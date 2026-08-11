class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 1;
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1) {
                end = j + 1;
            } else {
                break;
            }
        }
        int prefSum = 0;
        for (int i = start; i < end; i++) {
            prefSum += nums[i];
        }
        while (true) {
            if (find(nums.begin(), nums.end(), prefSum) == nums.end()) {
                return prefSum;
            } else {
                prefSum++;
            }
        }
        return 0;
    }
};