// Last updated: 20/07/2026, 10:38:29
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long bulb=(brightness+2)/3;
        sort(intervals.begin(),intervals.end());
        long long ontime=0;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }else{
                ontime+=(long long)(end-start+1);
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ontime+=(long long)(end-start+1);
        return bulb*ontime;
    }
};