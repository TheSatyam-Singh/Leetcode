// Last updated: 20/07/2026, 11:26:38
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node]=1;
        for (int i:adj[node]) {
            if (!vis[i]) {
                dfs(i,adj,vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjlist(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int>vis(n,0);
        dfs(source,adjlist,vis);
        return vis[destination];
    }
};