class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int mx=0;
        for(char i : s){
            if(i=='('){
                count++;
                mx=max(mx,count);
            }
            if(i==')'){
                count--;
            }
        }
        return mx;
    }
};