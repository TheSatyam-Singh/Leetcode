// Last updated: 20/07/2026, 11:24:48
class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*');
        string left = p.substr(0, star);
        string right = p.substr(star + 1);
        int n = s.size();
        for (int i = 0; i + left.size() <= n; i++) {
            if (s.substr(i, left.size()) != left){
                continue;
            }
            for (int j = i + left.size(); j <= n - right.size(); j++) {
                if (s.substr(j, right.size()) == right) {
                    return true;
                }
            }
        }
        return false;
    }
};