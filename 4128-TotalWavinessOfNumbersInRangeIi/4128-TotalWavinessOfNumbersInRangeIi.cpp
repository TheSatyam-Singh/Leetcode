// Last updated: 20/07/2026, 10:40:01
class Solution {
public:
    using ll = long long;
    struct Node {
        ll cnt;   
        ll wav;   
    };
    string s;
    Node dp[17][11][11][2];
    bool vis[17][11][11][2];
    Node dfs(int pos, bool tight, bool started,
             int prev2, int prev1) {
        if (pos == s.size()) {
            return {1, 0};
        }
        if (!tight && vis[pos][prev2][prev1][started]) {
            return dp[pos][prev2][prev1][started];
        }
        int limit = tight ? s[pos] - '0' : 9;
        ll totalCnt = 0;
        ll totalWav = 0;
        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);
            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, newTight,
                               false, 10, 10);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            }
            else if (!started) {
                Node nxt = dfs(pos + 1, newTight,
                               true, 10, d);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            }
            else if (prev2 == 10) {
                Node nxt = dfs(pos + 1, newTight,
                               true, prev1, d);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            }
            else {
                int add = 0;
                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d)) {
                    add = 1;
                }
                Node nxt = dfs(pos + 1, newTight,
                               true, prev1, d);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav + 1LL * add * nxt.cnt;
            }
        }
        Node ans = {totalCnt, totalWav};
        if (!tight) {
            vis[pos][prev2][prev1][started] = true;
            dp[pos][prev2][prev1][started] = ans;
        }
        return ans;
    }
    long long solve(long long n) {
        if (n < 0) return 0;
        s = to_string(n);
        memset(vis, 0, sizeof(vis));
        return dfs(0, true, false, 10, 10).wav;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};