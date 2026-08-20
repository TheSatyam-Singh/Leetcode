class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end(),[](auto &a,auto &b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        });
        vector<int>res;
        for(auto it:ans){
            for(int i=0;i<it.second;i++){
                res.push_back(it.first);
            }
        }
        return res;
    }
};