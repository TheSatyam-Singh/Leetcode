// Last updated: 20/07/2026, 10:39:02
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n - i - 1]) {
                return i;
            }
        }
        return -1;
    }
};
