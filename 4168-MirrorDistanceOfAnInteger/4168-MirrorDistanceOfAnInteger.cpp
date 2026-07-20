// Last updated: 20/07/2026, 10:39:48
class Solution {
public:
    int mirrorDistance(int n) {
        int x=n;
        int y=0;
        while (x>0) {
            y=y*10+x%10;
            x/=10;
        }
        return abs(n-y);
    }
};