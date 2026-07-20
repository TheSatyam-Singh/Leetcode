// Last updated: 20/07/2026, 10:40:05
class Solution {
public:
    vector<int> parent, rank_, parity;
    
    int find(int x) {
        if (parent[x] != x) {
            int root = find(parent[x]);
            parity[x] ^= parity[parent[x]];
            parent[x] = root;
        }
        return parent[x];
    }
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank_.resize(n, 0);
        parity.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int count = 0;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            
            int pu = find(u);
            int pv = find(v);
            
            if (pu == pv) {
                if ((parity[u] ^ parity[v]) == w) {
                    count++;
                }
            } else {
                if (rank_[pu] < rank_[pv]) {
                    swap(pu, pv);
                    swap(u, v);
                }
                
                parent[pv] = pu;
                parity[pv] = parity[u] ^ w ^ parity[v];
                
                if (rank_[pu] == rank_[pv]) {
                    rank_[pu]++;
                }
                
                count++;
            }
        }
        
        return count;
    }
};