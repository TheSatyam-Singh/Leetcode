// Last updated: 20/07/2026, 11:24:56
class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int>ans;
        for (int i:nums){
            int sum=0;
            int temp=i;
            while (temp>0){
                sum+=temp%10;
                temp/=10;
            }
            ans.push_back(sum);
        } 
        return *min_element(ans.begin(),ans.end()); 
    }
};