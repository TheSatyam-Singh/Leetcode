class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                nums[ans]=nums[i];
                ans++;
            }
        }
        nums.resize(ans);
        return nums;
    }
};