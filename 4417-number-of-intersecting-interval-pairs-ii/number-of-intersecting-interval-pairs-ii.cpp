 class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            ans.push_back({intervals[i][0],-1});
            ans.push_back({intervals[i][1],1});
        }
        sort(ans.begin(),ans.end());
        long long res=0;
        long long tmp=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i].second==-1){
                res+=tmp;
                tmp++;
            }else{
                tmp--;
            }
        }
        return res;
    }
};