// Last updated: 20/07/2026, 10:39:37
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> result;

        for(int i = 0; i < nums.size(); i++) {
            long long current = nums[i];

            while(!result.empty() && result.back() == current) {
                current += result.back();
                result.pop_back();
            }

            result.push_back(current);
        }

        return result;
    }
};