class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        deque<pair<int,int>>dq;
        dist[0][0]=0;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto p=dq.front();
            dq.pop_front();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int cost=0;
                    if(grid[x][y]!=i+1){
                        cost=1;
                    }
                    if(dist[x][y]+cost<dist[nx][ny]){
                        dist[nx][ny]=dist[x][y]+cost;
                        if(cost==0){
                            dq.push_front({nx,ny});
                        }
                        else{
                            dq.push_back({nx,ny});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};