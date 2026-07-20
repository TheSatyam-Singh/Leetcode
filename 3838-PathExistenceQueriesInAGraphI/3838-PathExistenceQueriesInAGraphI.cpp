// Last updated: 20/07/2026, 10:42:28
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>ans(n);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+(nums[i]-nums[i-1]>maxDiff);
        }
        vector<bool>res;
        for(auto i:queries){
                res.push_back(ans[i[0]]==ans[i[1]]); 
            }
        return res;
    }
};