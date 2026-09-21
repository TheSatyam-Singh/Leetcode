class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int orange=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }else if(grid[i][j]==1){
                    orange++;
                }
            }
        }
        if(orange==0){
            return 0;
        }
        int time=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()) {
            auto p=q.front();
            q.pop();
            int x=p.first.first;
            int y=p.first.second;
            int t=p.second;
            time=max(time,t);
            for(int i=0;i<4;i++) {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m &&
                   ny>=0 && ny<n &&
                   grid[nx][ny]==1) {
                    grid[nx][ny]=2;
                    orange--;
                    q.push({{nx,ny},t+1});
                }
            }
        }
        if(orange>0){
            return -1;
        }
        return time;
    }
};