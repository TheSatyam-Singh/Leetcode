class Solution {
public:
    int maxPower(string s) {
        int mx=1;
        int ans=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                ans++;
                mx=max(mx,ans);
            }else{
                ans=1;
            }
        }
        return mx;
    }
};