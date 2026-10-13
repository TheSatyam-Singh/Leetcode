class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<long long>sq;
        for(int i:nums){
            sq.push_back(1LL*i*i);
        }
        sort(sq.begin(),sq.end());
        for(int i=0;i<nums.size();i++){
            if(i<n/2){
                ans-=sq[i];
            }else{
                ans+=sq[i];
            }
        }
        return ans;
    }
};