class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        map<string,string>mp;
        for (int i=0;i<knowledge.size();i++) {
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                int j=i+1;
                while(s[j]!=')'){
                    j++;
                }
                string str=s.substr(i+1,j-i-1);
                if(mp.find(str)!=mp.end()){
                    ans+=mp[str];
                }else{
                    ans+="?";
                }
                i=j;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};