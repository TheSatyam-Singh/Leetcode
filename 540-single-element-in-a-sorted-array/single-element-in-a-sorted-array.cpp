class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=(right+left)/2;
            if(mid%2==1){
                mid--;
            }
            if(nums[mid]==nums[mid+1]){
                left=mid+2;
            }else{
                right=mid;
            }
        }
        return nums[left];
        // int ans=0;
        // for(int i:nums){
        //     ans^=i;
        // }
        // return ans;
    }
};