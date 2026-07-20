// Last updated: 20/07/2026, 11:26:14
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left;
        vector<int>right;
        vector<int>middle;
        for(int i:nums){
            if(i<pivot){
                left.push_back(i);
            }
            if(i==pivot){
                middle.push_back(i);
            }
            if(i>pivot){
                right.push_back(i);
            }
        }
        left.insert(left.end(),middle.begin(),middle.end());
        left.insert(left.end(),right.begin(),right.end());
        return left;
    }
};