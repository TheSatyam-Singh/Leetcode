// Last updated: 20/07/2026, 10:37:58
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int xcount=0;
        int ycount=0;
        string ans;
        for(char i:s){
            if(i==x){
                xcount++;
            } else if(i==y){
                ycount++;
            }else{
                ans+=i;
            }
        }
        string res;
        res.reserve(s.length());
        res.append(ycount,y);
        res+=ans;
        res.append(xcount,x);
        return res;
    }
};