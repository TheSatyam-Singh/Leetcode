// Last updated: 20/07/2026, 21:00:37
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int n=grid.size();
5        int m=grid[0].size();
6        while(k--){
7            vector<vector<int>> ans=grid;
8            for(int i=0;i<n;i++){
9                for(int j=0;j<m;j++){
10                    if(j<m-1){
11                        ans[i][j+1]=grid[i][j];
12                    }
13                    else if(i<n-1){
14                        ans[i+1][0]=grid[i][j];
15                    }
16                    else{
17                        ans[0][0]=grid[i][j];
18                    }
19                }
20            }
21            grid=ans;
22        }
23        return grid;
24    }
25};