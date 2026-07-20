// Last updated: 20/07/2026, 11:25:13
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int sum=nums2[0]-nums1[0];
        return sum;
    }
};