// Last updated: 20/07/2026, 11:26:42
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        /*for(int i=mn;i>=1;i--){
            if (mn%i==0 && mx%i==0){
                return i;
            }
        }
        return 1;*/
        return gcd(mn,mx);
    }
};