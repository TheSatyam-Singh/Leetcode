class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int ins=0;
        for(char i:s){
            if(i=='('){
                open++;
            }else if(i==')' && open>0){
                open--;
            }else{
                ins++;
            }
        }
        return open+ins;
    }
};