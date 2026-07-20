// Last updated: 20/07/2026, 11:25:53
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int esum=0;
        int dsum=0;
        for(int i:nums){
            esum+=i;
            int temp=i;
            while(temp>0){
                int d=temp%10;
                dsum+=d;
                temp/=10;
            }
        }
        return abs(esum-dsum);
    }
};