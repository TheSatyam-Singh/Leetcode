class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int mx = -1;
        int smx = -1;
        for (char c : s) {
            int d = c - '0';
            if (d > mx) {
                smx = mx;
                mx = d;
            } else if (d > smx) {
                smx = d;
            }
        }
        return mx * smx;
    }
};