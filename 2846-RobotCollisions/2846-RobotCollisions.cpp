// Last updated: 20/07/2026, 10:52:32
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string d) {
        int n = pos.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return pos[a] < pos[b];
        });
        vector<int> st;
        vector<bool> alive(n, true);
        for(int i : idx){
            if(d[i] == 'R'){
                st.push_back(i);
            }
            else{
                while(!st.empty()){
                    int j = st.back();

                    if(h[j] < h[i]){
                        alive[j] = false;
                        st.pop_back();
                        h[i]--;
                    }
                    else if(h[j] > h[i]){
                        alive[i] = false;
                        h[j]--;
                        break;
                    }
                    else{
                        alive[j] = false;
                        alive[i] = false;
                        st.pop_back();
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(alive[i]) ans.push_back(h[i]);
        }
        return ans;
    }
};