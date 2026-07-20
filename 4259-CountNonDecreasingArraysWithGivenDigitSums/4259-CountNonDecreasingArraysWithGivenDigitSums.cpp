// Last updated: 20/07/2026, 10:39:04
class Solution {
public:
    const int MOD = 1e9 + 7;
    int digitSum(int num) {
        int s = 0;
        while (num > 0) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }
    int countArrays(vector<int>& digitSumArr) {
        int n = digitSumArr.size();
        unordered_map<int, vector<int>> mp;
        for (int num = 0; num <= 5000; num++) {
            int d = digitSum(num);
            mp[d].push_back(num);
        }
        vector<vector<int>> cand(n);
        for (int i = 0; i < n; i++) {
            if (mp.count(digitSumArr[i])) {
                cand[i] = mp[digitSumArr[i]];
            }
            if (cand[i].empty()) return 0;
        }
        vector<vector<long long>> pref(n);
        pref[0].resize(cand[0].size() + 1, 0);
        for (int j = 0; j < cand[0].size(); j++) {
            pref[0][j + 1] = (pref[0][j] + 1) % MOD;
        }
        for (int i = 1; i < n; i++) {
            pref[i].resize(cand[i].size() + 1, 0);
            for (int j = 0; j < cand[i].size(); j++) {
                int val = cand[i][j];
                int l = 0, r = cand[i - 1].size();
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (cand[i - 1][mid] <= val) l = mid + 1;
                    else r = mid;
                }
                long long ways = pref[i - 1][l];
                pref[i][j + 1] = (pref[i][j] + ways) % MOD;
            }
        }
        return pref[n - 1][cand[n - 1].size()];
    }
};