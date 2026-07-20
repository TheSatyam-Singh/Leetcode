// Last updated: 20/07/2026, 10:39:23
class Solution {
public:
    int countCommas(int n) {
        if (n<1000){
            return 0;
        } else{
            return n-999;
        }
    }
};