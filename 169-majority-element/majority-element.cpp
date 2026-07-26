class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto i:mp){
            if(i.second>(n/2)){
                count=i.first;
            }
        }
        return count;
    }
};