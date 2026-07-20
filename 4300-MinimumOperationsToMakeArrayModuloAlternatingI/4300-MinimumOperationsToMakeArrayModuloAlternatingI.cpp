// Last updated: 20/07/2026, 10:38:38
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int minops=INT_MAX;
        for(int a=0;a<k;a++){
            for(int b=0;b<k;b++){
                if(a==b){
                    continue;
                }
                int ops=0;
                for(int i=0;i<n;i++){
                    int c=nums[i]%k;
                    if(c<0){
                        c+=k;
                    }
                    int targ=(i%2==0)?a:b;
                    int diff=abs(c-targ);
                    ops+=min(diff,k-diff);
                }
                minops=min(minops,ops);
            }
        }
        return minops;
    }
};