// Last updated: 20/07/2026, 10:52:45
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum=0;
        for (int i:nums) {
            totalSum+=i;
        }
        vector<int>answer;
        int leftSum=0;
        int rightSum=totalSum;
        for (int i=0;i<nums.size();i++) {
            rightSum-=nums[i];
            answer.push_back(abs(leftSum-rightSum));
            leftSum+=nums[i];
        }
        return answer;
    }
};