// Last updated: 20/07/2026, 10:38:00
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long s1=s;
        long long m1=m;
        long long mxval=0;
        if(n==1){
            mxval=s1; 
        }else {
            long long k=n/2;
            mxval=s1+k*m1-(k-1);
        }
        long long mxval1=0;
        if(n==1){
            mxval1=s1;
        }else if(n==2){
            mxval1=s1-1;
        } else{
            long long k=(n-1)/2;
            mxval1=s1+k*m1-k;
        }
        return max(mxval,mxval1);
    }
};