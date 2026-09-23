class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total=0;
        for(int i:nums){
            total+=i;
        }
        int target=total-x;
        if(target<0){
            return -1;
        }
        if(target==0){
            return n;
        }
        int sum=0;
        int j=0;
        int mx=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>target){
                sum-=nums[j];
                j++;
            }
            if(sum==target){
                mx=max(mx,i-j+1);
            }
        }
        if(mx==-1){
            return -1;
        }
        return n-mx;
    }
};