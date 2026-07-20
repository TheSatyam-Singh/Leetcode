// Last updated: 20/07/2026, 10:39:58
class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long sum=0;
        long long num=0;
        for(char i:s){
            if(i=='0'){
                continue;
            }
            int digit=i-'0';
            sum+=digit;
            num=num*10+digit;
        }
        return sum*num;
    }
};