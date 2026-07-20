// Last updated: 20/07/2026, 10:39:53
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> prev;
        int ans = nums.size()+1;
        for (int i=0; i<nums.size();i++) {
            int x=nums[i],y=0;
            while (x>0) {
                y=y*10+x%10;
                x/= 10;
            }
            if (prev.count(nums[i])) {
                ans=min(ans,i-prev[nums[i]]);
            }
            prev[y]=i;
        }
        return ans == nums.size()+1?-1:ans;
    }
};