class Solution {
public:
    static bool compare(int a, int b) {
        if (a % 2 != b % 2) {
            return a % 2 == 0;
        }
        return a < b;
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end(), compare);
        sort(target.begin(), target.end(), compare);
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                count += abs(nums[i] - target[i]) / 2;
            }
        }
        return count/2;
    }
};
