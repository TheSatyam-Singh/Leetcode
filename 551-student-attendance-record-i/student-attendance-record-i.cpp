class Solution {
public:
    bool checkRecord(string s) {
        int ab = 0;
        int late = 0;
        for (char i : s) {
            if (i == 'A') {
                ab++;
                late = 0;
                if (ab >= 2) {
                    return false;
                }
            } else if (i == 'L') {
                late++;
                if (late >= 3) {
                    return false;
                }
            } else {
                late = 0;
            }
        }
        return true;
    }
};