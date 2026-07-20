// Last updated: 20/07/2026, 10:42:34
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (!rows) return 0;
        int cols = grid[0].size();
        if (!cols) return 0;
        struct Node {
            int x, y, val;
        };
        vector<Node> arr;
        arr.reserve(rows * cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] > 0) {
                    arr.push_back({i, j, grid[i][j]});
                }
            }
        }
        sort(arr.begin(), arr.end(), [](const Node& a, const Node& b) {
            return a.val > b.val;
        });
        int h = rows + 1;
        int w = cols + 1;
        vector<int> tree(h * w);
        auto upd = [&](int r, int c, int v) {
            r++;
            c++;
            for (int i = r; i < h; i += i & -i) {
                int base = i * w;
                for (int j = c; j < w; j += j & -j) {
                    tree[base + j] += v;
                }
            }
        };
        auto get = [&](int r, int c) {
            if (r <= 0 || c <= 0) return 0;
            int sum = 0;
            for (int i = r; i > 0; i -= i & -i) {
                int base = i * w;
                for (int j = c; j > 0; j -= j & -j) {
                    sum += tree[base + j];
                }
            }
            return sum;
        };
        auto area = [&](int r1, int r2, int c1, int c2) {
            r1 = max(0, r1);
            r2 = min(rows - 1, r2);
            c1 = max(0, c1);
            c2 = min(cols - 1, c2);
            if (r1 > r2 || c1 > c2) return 0;
            r1++;
            r2++;
            c1++;
            c2++;
            return get(r2, c2)-get(r1 - 1, c2)- get(r2, c1 - 1)+ get(r1 - 1, c1 - 1);
        };
        int res = 0;
        int idx = 0;
        int sz = arr.size();
        while (idx < sz) {
            int cur = arr[idx].val;
            int st = idx;
            while (idx < sz && arr[idx].val == cur) {
                idx++;
            }
            for (int i = st; i < idx; ++i) {
                int r = arr[i].x;
                int c = arr[i].y;
                int d = cur;
                int a = area(r - d + 1, r + d - 1, c - d, c + d);
                int b = area(r - d, r + d, c - d + 1, c + d - 1);
                int mid = area(r - d + 1, r + d - 1, c - d + 1, c + d - 1);
                if (a + b - mid == 0) {
                    res++;
                }
            }
            for (int i = st; i < idx; ++i) {
                upd(arr[i].x, arr[i].y, 1);
            }
        }
        return res;
    }
};