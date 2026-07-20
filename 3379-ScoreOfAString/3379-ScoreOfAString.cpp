// Last updated: 20/07/2026, 11:25:17
class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        int diff=0;
        for (int i=0;i<s.length()-1;i++){
            diff=abs((int)s[i]-(int)s[i+1]);
            sum=sum+diff;
        }
        return sum;
    }
};