class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        int sum1 = 0;
        int sum2 = 0;
        int quesl = 0;
        int quesr = 0;
        for (int i = 0; i < n; i++) {
            if (i < half) {
                if (num[i] == '?') {
                    quesl++;
                } else {
                    sum1 += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    quesr++;
                } else {
                    sum2 += num[i] - '0';
                }
            }
        }
        return (sum1 - sum2) * 2 != (quesr - quesl) * 9;
    }
};