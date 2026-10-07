class Solution {
public:
    vector<string>ans;
    void solve(string str, int start, int end, char open, char close){
        int bal=0;
        for(int i=start;i<str.size();i++){
            if(str[i]==open){
                bal++;
            }
            if(str[i]==close){
                bal--;
            }
            if(bal>=0){
                continue;
            }
            for(int j=end;j<=i;j++){
                if(str[j]==close && (j==end || str[j-1]!=close)){
                    solve(str.substr(0,j)+str.substr(j+1),i,j,open,close);
                }
            }
            return;
        }
        reverse(str.begin(),str.end());
        if(open=='('){
            solve(str,0,0,')','(');
        }
        else{
            ans.push_back(str);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s,0,0,'(',')');
        return ans;
    }
};