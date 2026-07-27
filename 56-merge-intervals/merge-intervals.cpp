class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort(intervals.begin(),intervals.end());
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int previous=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<= ans[previous][1]){
                ans[previous][1]=max(ans[previous][1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
                previous++;
            }
        }
        return ans;
    }
};