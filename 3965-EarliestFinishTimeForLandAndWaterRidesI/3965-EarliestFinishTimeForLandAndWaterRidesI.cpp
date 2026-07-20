// Last updated: 20/07/2026, 11:24:17
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            for (int j=0;j<waterStartTime.size();j++){
                int landEnd=landStartTime[i]+landDuration[i];
                ans=min(ans,max(landEnd, waterStartTime[j]) + waterDuration[j]);
                int waterEnd=waterStartTime[j]+waterDuration[j];
                ans=min(ans,max(waterEnd, landStartTime[i]) + landDuration[i]);
            }
        }
        return ans;
    }
};