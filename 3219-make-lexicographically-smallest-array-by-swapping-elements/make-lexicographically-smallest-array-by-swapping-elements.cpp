class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());

        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>gid;
        unordered_map<int,int>pos;
        int id=1;
        mp[id].push_back(temp[0]);
        gid[temp[0]]=id;
        for(int i=1;i<nums.size();i++){
            if(temp[i]-temp[i-1]>limit){
                id++;
            }
            mp[id].push_back(temp[i]);
            gid[temp[i]]=id;
        }
        for(int i=0;i<nums.size();i++){
            int count=gid[nums[i]];
            nums[i]=mp[count][pos[count]];
            pos[count]++;
        }
        return nums;
    }
};