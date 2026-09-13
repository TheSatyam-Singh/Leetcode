class Solution {
public:
    int arrangeCoins(int n) {
        int a=n;
        int i=1;
        while(a>=0){
            a=a-i;
            i++;
        }
        return i-2;
    }
};