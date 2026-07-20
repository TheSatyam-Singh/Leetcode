// Last updated: 20/07/2026, 11:26:02
class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }
        for (auto &p : freq) {
            p.second--;
            int target = 0;
            bool valid = true;
            for (auto &q : freq) {
                if (q.second == 0){
                    continue;
                }
                if (target == 0) {
                    target = q.second;
                } else if (q.second != target) {
                    valid = false;
                    break;
                }
            }
            if (valid){
                return true;
            }
            p.second++;
        }
        return false;
    }
};