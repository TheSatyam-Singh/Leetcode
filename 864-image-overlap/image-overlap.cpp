class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int a = -n + 1; a < n; a++) {
            for (int b = -n + 1; b < n; b++) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i + a >= 0 && i + a < n &&
                            j + b >= 0 && j + b < n &&
                            img1[i][j] == 1 &&
                            img2[i + a][j + b] == 1) {
                            count++;
                        }
                    }
                }
                ans = max(ans, count);
            }
             
        }
        return ans;
    }
};