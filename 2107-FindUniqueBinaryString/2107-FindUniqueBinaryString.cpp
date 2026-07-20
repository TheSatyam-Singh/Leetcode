// Last updated: 20/07/2026, 11:26:41
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        string ans="";
        for (int i=0;i<n;i++) {
            if (nums[i][i]=='0')
                ans+='1';
            else
                ans+='0';
        }
        return ans;
    }
};