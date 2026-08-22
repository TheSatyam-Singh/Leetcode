class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>sum;
        int n=code.size();
        if (k == 0) {
            return vector<int>(n, 0);
        }
        for(int i=0;i<n;i++){
            int tsum=0;
            if(k>0){
                for(int j=1;j<=k;j++){
                    tsum+=code[(i+j)%n];
                }
                sum.push_back(tsum);
            }else{
                for(int j=1;j<=abs(k);j++){
                    tsum+=code[(i-j+n)%n];
                }
                sum.push_back(tsum);
            }
        }
        return sum;
    }
};