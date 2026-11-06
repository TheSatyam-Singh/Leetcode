class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int n=nums.size()/4;
        int ans=0;
        for(auto it:mp){
            if(it.second>n){
                ans=it.first;
            }
        }
        return ans;
    }
};