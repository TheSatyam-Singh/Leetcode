// Last updated: 20/07/2026, 10:38:31
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (size_t i = 0; i < s.length() - 1; ++i) {
            if (abs(s[i] - s[i + 1]) > 2) {
                return false;
            }
        }
        return true;
    }
};
