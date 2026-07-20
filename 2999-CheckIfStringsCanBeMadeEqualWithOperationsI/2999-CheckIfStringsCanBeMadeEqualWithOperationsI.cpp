// Last updated: 20/07/2026, 11:25:36
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        char temp;
        for (int i=0;i<2;i++){
            if (s1[i]==s2[i]){
                continue;
            }
            temp=s1[i];
            s1[i]=s1[i+2];
            s1[i+2]=temp;
        }
        if (s1==s2){
            return true;
        }
        else {
            return false;
        }
    }
};