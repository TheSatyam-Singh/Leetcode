class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>>mp;
        for(int i=0;i<reservedSeats.size();i++){
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int count=(n-mp.size())*2;
        for(auto it:mp){
            set<int>st=it.second;
            bool left=(!st.count(2) && !st.count(3) && !st.count(4) && !st.count(5));
            bool mid=(!st.count(4) && !st.count(5) && !st.count(6) && !st.count(7));
            bool right=(!st.count(6) && !st.count(7) && !st.count(8) && !st.count(9));
            if(left && right){
                count+=2;
            }else if(left || mid || right){
                count++;
            }
        }
        return count;
    }
};