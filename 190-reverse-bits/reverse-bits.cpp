class Solution {
public:
    vector<long long>d2b(long long n){
        int i=0;
        vector<long long>binNum(32,0);
        while(n>0){
            binNum[i]=n%2;
            n/=2;
            i++;
        }
        return binNum;
    }
    unsigned int b2d(vector<long long>&bin){
        unsigned int deci=0;
        unsigned int base=1;
        for(int i=31;i>=0;i--){
            if(bin[i]==1){
                deci+=base;
            }
            if(i>0){
                base*=2;
            }
        }
        return deci;
    }
    int reverseBits(int n) {
        unsigned int a=static_cast<unsigned int>(n);
        vector<long long>bin=d2b(a);
        unsigned int b=b2d(bin);
        return static_cast<int>(b);
    }
};