class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            int mn = *min_element(nums.begin(), nums.end());
            int idxmn = find(nums.begin(), nums.end(), mn)-nums.begin();
            nums[idxmn] = mn * multiplier;
        }
        return nums;
    }
};