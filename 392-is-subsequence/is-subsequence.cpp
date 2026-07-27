class Solution {
public:
    bool isSubsequence(string s, string t) {
        int scount=0;
        int tcount=0;
        while(scount<s.length() && tcount<t.length()){
            if(s[scount]==t[tcount]){
                scount++;
            }
            tcount++;
        }
        return scount==s.length();
    }
};