class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>seen(nums.begin(),nums.end());
        for (int i=1;i<=(int)nums.size()+1;i++) {
            if (seen.find(i)==seen.end()){
                return i;
            }
        }
        return nums.size()+1;   
    }
};