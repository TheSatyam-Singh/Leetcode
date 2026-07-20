// Last updated: 20/07/2026, 10:52:41
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> indexMap;
        for(int i=0;i<n;i++){
            indexMap[nums[i]].push_back(i);
        }
        vector<long long> result(n,0);
        for(auto &entry:indexMap){
            vector<int>& indices=entry.second;
            int m=indices.size();
            long long totalSum=0;
            for(int idx:indices){
                totalSum+=idx;
            }
            long long leftSum=0;
            for(int i=0;i<m;i++){
                int currentIndex=indices[i];
                long long rightSum=totalSum-leftSum-currentIndex;
                long long leftContribution=(long long)currentIndex*i-leftSum;
                long long rightContribution=rightSum-(long long)currentIndex*(m-i-1);
                result[currentIndex]=leftContribution+rightContribution;
                leftSum+=currentIndex;
            }
        }
        return result;
    }
};