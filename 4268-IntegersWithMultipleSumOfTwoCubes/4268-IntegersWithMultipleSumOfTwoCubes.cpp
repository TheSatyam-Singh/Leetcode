// Last updated: 20/07/2026, 10:38:56
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> cnt;
        
        int mx = pow(n, 1.0/3) + 2;
        
        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j++) {
                long long s = (long long)i * i * i + (long long)j * j * j;
                if (s <= n) {
                    cnt[s]++;
                }
            }
        }
        
        vector<int> res;
        for (auto& p : cnt) {
            if (p.second >= 2) {
                res.push_back(p.first);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};