class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1;
        long long high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            long long mid=(low+high)/2;
            long long totalhr=0;
            for(int i=0;i<piles.size();i++){
                totalhr+=ceil(piles[i]/double(mid));
            }
            if(totalhr<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
