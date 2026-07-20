// Last updated: 20/07/2026, 10:40:22
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pref(2*n+1,0);
        pref[n]=1;
        int count=n;
        long long ans=0;
        long long presum = 0;
        for(int i:nums){
            if(i==target){
                presum+=pref[count];
                count++;
                pref[count]++;
            } else{
                count--;
                presum-=pref[count];
                pref[count]++;
            }
            ans+=presum;
        }
        return ans;
    }
};