// Last updated: 20/07/2026, 10:38:14
class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = {0};
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            freq[digit]++;
            temp /= 10;
        }
        int totalScore = 0;
        for (int d = 0; d <= 9; d++) {
            if (freq[d] > 0) {
                totalScore += d * freq[d];
            }
        }
        return totalScore;
    }
};
