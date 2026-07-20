// Last updated: 20/07/2026, 10:40:04
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(mp.find(num)==mp.end()){
                mp[num]=vector<int>();
            }
            mp[num].push_back(i);
            if(mp[num].size()>3){
                mp[num].erase(mp[num].begin());
            }   
            if(mp[num].size()==3){
                mini=min(mini,2*(mp[num][2]-mp[num][0]));
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};