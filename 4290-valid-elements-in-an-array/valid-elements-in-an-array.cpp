class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,INT_MIN);
        vector<int>right(n,INT_MIN);
        vector<int>ans;
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],nums[i+1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>left[i] || nums[i]>right[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};