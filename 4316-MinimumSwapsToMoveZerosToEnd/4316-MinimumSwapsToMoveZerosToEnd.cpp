// Last updated: 20/07/2026, 10:38:17
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        int swap=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                k++;
            }
        }
        for(int i=0;i<k;i++){
            if(nums[i]==0){
                swap++;
            }
        }
        return swap;
    }
};