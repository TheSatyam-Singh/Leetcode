class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookie=s.size();
        if(cookie==0){
            return 0;
        }
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int mx=0;
        int cookieidx=cookie-1;
        int idx=g.size()-1;
        while(cookieidx>=0 && idx>=0){
            if(s[cookieidx]>=g[idx]){
                mx++;
                cookieidx--;
                idx--;
            }else{
                idx--;
            }
        }
        return mx;
    }
};