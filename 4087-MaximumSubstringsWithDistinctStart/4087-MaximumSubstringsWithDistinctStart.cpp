// Last updated: 20/07/2026, 10:40:20
class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st(s.begin(), s.end());
        return st.size();
    }
};