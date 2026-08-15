class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        while(i<nums.size() && nums[i]==temp[i]){
            i++;
        }
        if(i==nums.size()){
            return 0;
        }
        while(j>=0 && nums[j]==temp[j]){
            j--;
        }
        return j-i+1;
    }
};