class Solution {
public:
    int largestInteger(int n, int s) {
        int ans=0;
        if(9*n<s){
            return -1;
        }
        for(int i=0;i<n;i++){
            int mn=min(9,s);
            ans=ans*10+mn;
            s-=mn;
        }
        return ans;
    }
};