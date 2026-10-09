class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            ans.push_back(n);
            for(auto it:adj[n]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()!=V){
            return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};