// Last updated: 20/07/2026, 10:52:51
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            for (char j:s){
                ans.push_back(j-'0');
            }
        }
        return ans;
    }
};