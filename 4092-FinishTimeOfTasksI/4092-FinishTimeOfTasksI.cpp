// Last updated: 20/07/2026, 10:40:18
class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>tree(n);
        for(auto & e:edges){
            tree[e[0]].push_back(e[1]);
        }
        auto dfs=[&](auto& self, int node)-> long long{
            if (tree[node].empty()){
                return baseTime[node];
            }
            long long earlier=-1;
            long long latest=-1;
            for(int child:tree[node]){
                long long t=self(self,child);
                if(earlier==-1 || t<earlier){
                    earlier=t;
                }
                if(latest==-1 || t>latest){
                    latest=t;
                }
            }
            return latest+(latest-earlier)+baseTime[node];
        };
        return dfs(dfs,0);
    }
    
};