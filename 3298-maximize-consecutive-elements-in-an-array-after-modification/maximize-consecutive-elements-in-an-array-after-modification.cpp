class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i+1]=mp[i]+1;
            mp[i]=mp[i-1]+1;
            ans=max({ans,mp[i],mp[i+1]});
        }
        return ans;
    }
};