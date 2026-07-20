// Last updated: 20/07/2026, 10:37:39
1class Solution {
2public:
3    void dfs(int i, int j, vector<vector<char>>& grid) {
4        int m=grid.size();
5        int n=grid[0].size();
6        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0')
7            return;
8        grid[i][j]='0';
9        dfs(i+1,j,grid);
10        dfs(i-1,j,grid);
11        dfs(i,j+1,grid);
12        dfs(i,j-1,grid);
13    }
14    int numIslands(vector<vector<char>>& grid) {
15        int m=grid.size();
16        int n=grid[0].size();
17        int count=0;
18        for (int i=0;i<m;i++) {
19            for (int j=0;j<n;j++) {
20                if (grid[i][j]=='1') {
21                    count++;
22                    dfs(i,j,grid);
23                }
24            }
25        }
26        return count;
27    }
28};