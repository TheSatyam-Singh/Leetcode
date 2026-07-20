// Last updated: 20/07/2026, 10:38:26
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int ans=0;
        while(n>0){
            if((n&3)==3){
                ans++;
            }
            n>>=1;
        }
        return ans==1;
    }
};