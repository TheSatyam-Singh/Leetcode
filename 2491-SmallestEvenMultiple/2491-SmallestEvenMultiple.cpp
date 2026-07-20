// Last updated: 20/07/2026, 11:26:05
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0){
            return n;
        }else{
            return n*2;
        }
    }
};