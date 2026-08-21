class Solution {
public:
    int dsum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int sqsum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool checkGoodInteger(int n) {
        if (sqsum(n) - dsum(n) >= 50) {
            return true;
        }
        return false;
    }
};