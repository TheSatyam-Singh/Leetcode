// Last updated: 20/07/2026, 10:40:09
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& arr) {
        int len = arr.size();
        int left = 1;
        int right = len;
        int best = len;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasUnique(arr, mid)) {
                best = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return best;
    }
private:
    bool hasUnique(const vector<int>& arr, int sz) {
        int n = arr.size();
        if (sz == 0 || sz > n) return false;
        long long mod1 = 1000000007;
        long long mod2 = 1000000009;
        long long base1 = 313;
        long long base2 = 317;
        long long mul1 = 1;
        long long mul2 = 1;
        for (int i = 0; i < sz; ++i) {
            mul1 = (mul1 * base1) % mod1;
            mul2 = (mul2 * base2) % mod2;
        }
        long long hash1 = 0;
        long long hash2 = 0;
        vector<uint64_t> vals;
        vals.reserve(n - sz + 1);
        for (int i = 0; i < n; ++i) {
            long long x1 = (arr[i] % mod1 + mod1) % mod1;
            long long x2 = (arr[i] % mod2 + mod2) % mod2;
            hash1 = (hash1 * base1 + x1) % mod1;
            hash2 = (hash2 * base2 + x2) % mod2;
            if (i >= sz) {
                long long y1 = (arr[i - sz] % mod1 + mod1) % mod1;
                long long y2 = (arr[i - sz] % mod2 + mod2) % mod2;
                hash1 = (hash1 - y1 * mul1) % mod1;
                hash2 = (hash2 - y2 * mul2) % mod2;
                if (hash1 < 0) hash1 += mod1;
                if (hash2 < 0) hash2 += mod2;
            }
            if (i >= sz - 1) {
                uint64_t code = ((uint64_t)hash1 << 32) | (uint32_t)hash2;
                vals.push_back(code);
            }
        }
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); ++i) {
            bool prev = (i > 0 && vals[i] == vals[i - 1]);
            bool next = (i + 1 < vals.size() && vals[i] == vals[i + 1]);
            if (!prev && !next) {
                return true;
            }
        }
        return false;
    }
};