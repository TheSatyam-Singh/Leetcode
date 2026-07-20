// Last updated: 20/07/2026, 10:38:08
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD=1000000007;
        long long count=0;
        long long count1=0;
        long long swap=0;
        for(int i:nums){
            if(i<a){
                swap=(swap+count+count1)%MOD;
            } else if(i<=b){
                swap=(swap+count1)%MOD;
                count++;
            }else{
                count1++;
            }
        }
        return swap;
    }
};