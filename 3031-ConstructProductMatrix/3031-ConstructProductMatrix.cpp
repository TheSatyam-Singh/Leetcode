// Last updated: 20/07/2026, 11:25:33
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        vector<int> arr;
        
        for (auto &row : grid) {
            for (int x : row) {
                arr.push_back(x);
            }
        }

        int size = arr.size();
        vector<long long> res1(size, 1), res2(size, 1);

        for (int i = 1; i < size; i++) {
            res1[i] = (res1[i-1] * arr[i-1]) % MOD;
        }

        for (int i = size-2; i >= 0; i--) {
            res2[i] = (res2[i+1] * arr[i+1]) % MOD;
        }
        vector<vector<int>> ans(n, vector<int>(m));
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = (res1[k] * res2[k]) % MOD;
                k++;
            }
        }
        return ans;
    }
};