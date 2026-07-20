// Last updated: 20/07/2026, 10:38:46
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        int even=0;
        int odd=0;
        for(int x:nums){
            if(x%2==0){
                even++;
            }else{
                odd++;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even--;
                ans[i]=odd;
            }else{
                odd--;
                ans[i]=even;
            }
        }
        return ans;
    }
};