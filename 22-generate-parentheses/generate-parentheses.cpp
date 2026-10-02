class Solution {
public:
    void solve(int open, int close, string res, vector<string>&ans,int n){
        if(open==n && close==n){
            ans.push_back(res);
            return;
        }
        if(open<n){
            solve(open+1,close,res+"(",ans,n);
        }
        if(close<open){
            solve(open,close+1,res+")",ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res;
        solve(0,0,res,ans,n);
        return ans;
    }
};