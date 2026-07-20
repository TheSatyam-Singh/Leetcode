// Last updated: 20/07/2026, 10:42:40
class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?');
        //T
        for(int i = 0; i < n; i++){
            if(s[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(ans[i+j] != '?' && ans[i+j] != t[j]) return "";
                    ans[i+j] = t[j];
                }
            }
        }
        string old = ans;
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == '?') ans[i] = 'a';
        }
        //F
        for(int i = 0; i < n; i++){
            if(s[i] == 'F'){
                string cur = ans.substr(i, m);
                if(cur == t){
                    bool ok = false;
                    for(int j = i + m - 1; j >= i; j--){
                        if(old[j] == '?'){
                            ans[j] = 'b';
                            ok = true;
                            break;
                        }
                    }
                    if(!ok){
                        return "";
                    }
                }
            }
        }
        return ans;
    }
};