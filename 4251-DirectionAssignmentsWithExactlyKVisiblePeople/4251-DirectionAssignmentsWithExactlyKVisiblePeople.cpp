// Last updated: 20/07/2026, 10:39:16
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long b, long long e) {
        long long r = 1;
        b %= MOD;
        while (e > 0) {
            if (e & 1) r = (r * b) % MOD;
            b = (b * b) % MOD;
            e >>= 1;
        }
        return r;
    }
    long long inv(long long x) {
        return power(x, MOD - 2);
    }
    long long nCr(int n, int r, vector<long long>& f, vector<long long>& fi) {
        if (r < 0 || r > n){
            return 0;
        }
        return f[n] * fi[r] % MOD * fi[n - r] % MOD;
    }

    int countVisiblePeople(int n, int pos, int k) {
        int l = pos;
        int r = n - 1 - pos;
        if (k > l + r){
            return 0;
        }
        vector<long long> f(n + 1), fi(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++){
            f[i] = f[i - 1] * i % MOD;
        }
        fi[n] = inv(f[n]);
        for (int i = n - 1; i >= 0; i--){
            fi[i] = fi[i + 1] * (i + 1) % MOD;
        }
        long long ans = 0;
        for (int i = 0; i <= l; i++) {
            int j = k - i;
            if (j >= 0 && j <= r) {
                long long w = nCr(l, i, f, fi) * nCr(r, j, f, fi) % MOD;
                w = w * 2 % MOD;
                ans = (ans + w) % MOD;
            }
        }
        return ans;
    }
};