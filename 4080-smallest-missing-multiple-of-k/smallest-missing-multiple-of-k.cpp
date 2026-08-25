class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        long long m = k;
        while (seen.count(m))
            m += k;
        return m;
    }
};