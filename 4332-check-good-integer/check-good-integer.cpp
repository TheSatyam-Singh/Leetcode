class Solution {
public:
    int sum(int n) {
        int dsum = 0;
        int sqsum = 0;
        while (n > 0) {
            int digit = n % 10;
            dsum += digit;
            sqsum += digit * digit;
            n /= 10;
        }
        return sqsum - dsum;
    }
    bool checkGoodInteger(int n) {
        if (sum(n) >= 50) {
            return true;
        }
        return false;
    }
};