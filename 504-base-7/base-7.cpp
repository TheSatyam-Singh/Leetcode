class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){
            return "0";
        }
        bool isneg=num<0;
        string ans="";
        int q=abs(num);
        while(q!=0){
            int r=q%7;
            q/=7;
            ans.insert(0,to_string(r));
        }
        if(isneg){
            ans.insert(0,"-");
        }
        return ans;
    }
};