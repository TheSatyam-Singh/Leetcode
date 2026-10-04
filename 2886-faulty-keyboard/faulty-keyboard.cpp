class Solution {
public:
    string finalString(string s) {
        string ans="";
        for(char i:s){
            if(i=='i'){
                reverse(ans.begin(),ans.end());
            }else{
                ans+=i;
            }
        }
        return ans;
    }
};