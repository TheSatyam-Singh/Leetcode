// Last updated: 20/07/2026, 10:38:10
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>covered(n,-1);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int start=max(0,i-lights[i]);
                int end=min(n-1,i+lights[i]);
                covered[start]=max(covered[start],end);
            }
        }
        int addbulb=0;
        int coverleft=-1;
        for(int i=0;i<n;i++){
            coverleft=max(coverleft,covered[i]);
            if(coverleft<i){
                addbulb++;
                coverleft=max(coverleft,i+2);
            }
        }
        return addbulb;
    }
};