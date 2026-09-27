class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string ans="";
        for(char i:s){
            if(i=='('){
                st.push(ans);
                ans="";
            }else if(i==')'){
                reverse(ans.begin(),ans.end());
                ans=st.top()+ans;
                st.pop();
            }else{
                ans+=i;
            }
        }
        return ans;
    }
};