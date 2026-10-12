class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long prod=1;
        for(long long i:nums){
            if(i==0){
                return 0;
            }
            if(i<0){
                prod=-prod;
            }
        }
        return prod;
    }
};