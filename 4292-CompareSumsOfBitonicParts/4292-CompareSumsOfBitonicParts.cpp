// Last updated: 20/07/2026, 10:38:50
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        vector<int>ans=nums;
        int peekidx=0;
        for (int i=0;i<nums.size();i++){
            if(nums[i+1]>nums[i]){
                peekidx=i+1;
            }else{
                break;
            }
        }
        long long asum=0;
        long long dsum=0;
        for(int i=0;i<=peekidx;i++){
            asum+=nums[i];
        }
        for(int i=peekidx;i<nums.size();i++){
            dsum+=nums[i];
        }
        if (asum>dsum){
            return 0;
        }
        if (dsum>asum){
            return 1;
        }
        return -1;
    }
};