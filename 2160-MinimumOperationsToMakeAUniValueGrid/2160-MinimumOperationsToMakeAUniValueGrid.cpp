// Last updated: 20/07/2026, 11:26:32
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<long long>ans;
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans.push_back(grid[i][j]);
            }
        }
        int len=ans.size();
        nth_element(ans.begin(),ans.begin()+len/2,ans.end());
        int finalno=ans[len/2];
        for(int i:ans){
            if (i%x!=finalno%x){
                return -1;
            }else{
                res+=abs(finalno-i)/x;
            }
        }
        return res;
    }
};