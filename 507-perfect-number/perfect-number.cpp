class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        int divsum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                divsum += i;
                if (i != num / i) {
                    divsum += num / i;
                }
            }
        }
        return divsum == num;
    }
};