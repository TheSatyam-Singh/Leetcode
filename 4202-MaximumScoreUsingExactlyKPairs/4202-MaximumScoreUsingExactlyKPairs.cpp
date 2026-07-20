// Last updated: 20/07/2026, 10:39:46
class Solution {
public:
    long long maxScore(vector<int>& first, vector<int>& second, int k) {
        int n = first.size();
        int m = second.size();
        long long bad = -1e18;

        vector<vector<vector<long long>>> best(
            n + 1,
            vector<vector<long long>>(m + 1,
                vector<long long>(k + 1, bad))
        );

        best[0][0][0] = 0;

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int pairs = 0; pairs <= k; pairs++) {
                    if(best[i][j][pairs] == bad)
                        continue;

                    if(i < n)
                        best[i + 1][j][pairs] =
                            max(best[i + 1][j][pairs], best[i][j][pairs]);

                    if(j < m)
                        best[i][j + 1][pairs] =
                            max(best[i][j + 1][pairs], best[i][j][pairs]);

                    if(i < n && j < m && pairs < k)
                        best[i + 1][j + 1][pairs + 1] =
                            max(best[i + 1][j + 1][pairs + 1],
                                best[i][j][pairs] + 1LL * first[i] * second[j]);
                }
            }
        }

        return best[n][m][k];
    }
};