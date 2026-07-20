// Last updated: 20/07/2026, 11:23:37
class Solution {
public:
    long long maxTotalValue(vector<int>& A, int k) {
        auto [min, max] = ranges::minmax(A);
        return (long long)(max - min) * k;
    }
};