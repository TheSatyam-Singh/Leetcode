class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            n/=10;
            sum+=digit*digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>vis;
        while(true){
            if(n==1){
                return true;
            }
            if(vis.find(n)!=vis.end()){
                return false;
            }
            vis.insert(n);
            n=solve(n);
        }
    }
};