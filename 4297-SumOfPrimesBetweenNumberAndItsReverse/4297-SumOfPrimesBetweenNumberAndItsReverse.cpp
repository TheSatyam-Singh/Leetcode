// Last updated: 20/07/2026, 10:38:43
class Solution {
public:
    int primereverse(int n){
        int revNum=0;
        while(n>0){
            revNum=revNum*10+n%10;
            n=n/10;
        }
        return revNum;
    }
    bool isPrime(int x){
        if(x<2){
            return false;
        }
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    int sumfunc(int n,int revnum){
        vector<int>ans;
        int start=min(n,revnum);
        int end=max(n,revnum);
        for(int i=start;i<=end;i++){
            if(isPrime(i)){
                ans.push_back(i);
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
    int sumOfPrimesInRange(int n){
        int a=primereverse(n);
        return sumfunc(n,a);
    }
};