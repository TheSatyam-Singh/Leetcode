// Last updated: 20/07/2026, 10:39:55
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for (auto &w : words) {
            if ((int)w.size() < k) continue;
            mp[w.substr(0,k)]++;
        }
        int ans = 0;
        for (auto &p : mp) {
            if (p.second >= 2) ans++;
        }
        return ans;
    }
};
