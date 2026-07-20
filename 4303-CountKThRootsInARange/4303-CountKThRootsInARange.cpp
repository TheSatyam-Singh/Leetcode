// Last updated: 20/07/2026, 10:38:34
class Solution {
public:
    int countKthRoots(int low, int high, int power_val) {
        if (power_val == 1) {
            return high - low + 1;
        }
        int ans = (low == 0) ? 1 : 0;
        long long num = 1;
        while (true) {
            long long val = 1;
            bool over = false;
            for (int i = 0; i < power_val; i++) {
                if (val > high / num) {
                    over = true;
                    break;
                }
                val *= num;
            }
            if (over || val > high) {
                break;
            }
            if (val >= low) {
                ans++;
            }
            num++;
        }
        return ans;
    }
};
