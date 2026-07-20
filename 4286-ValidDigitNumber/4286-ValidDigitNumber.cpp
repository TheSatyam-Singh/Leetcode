// Last updated: 20/07/2026, 10:38:51
class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        char targ=x+'0';
        if (s[0]==targ){
            return false;
        }
        for (int i=1;i<s.length();i++){
            if (s[i]==targ){
                return true;
            }
        }
        return false;
    }
};