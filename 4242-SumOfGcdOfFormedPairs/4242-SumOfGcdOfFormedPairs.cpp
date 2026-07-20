// Last updated: 20/07/2026, 10:39:24
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=0;
        for(int &i:nums){
            mx=max(mx,i);
            i=gcd(i,mx);
        }
        sort(nums.begin(),nums.end());
        long long ans=0;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            ans+=gcd(nums[i],nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};