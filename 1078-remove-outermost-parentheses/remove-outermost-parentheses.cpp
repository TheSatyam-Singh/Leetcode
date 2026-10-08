class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth=0;
        for(char i:s){
            if(i=='('){
                if(depth>0){
                    ans+=i;
                }
                depth++;
            }else{
                depth--;
                if(depth>0){
                    ans+=i;
                }
            }
        }
        return ans;
    }
};
