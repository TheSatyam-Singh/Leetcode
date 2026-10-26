class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int,char>mp;
        int pos=1;
        for(char i='A';i<='Z';i++){
            mp[pos]=i;
            pos++;
        }
        string ans="";
        while(columnNumber>0){
            columnNumber--;
            int rem=columnNumber%26;
            ans+=mp[rem+1];
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};