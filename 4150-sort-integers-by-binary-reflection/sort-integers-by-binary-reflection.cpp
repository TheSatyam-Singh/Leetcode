class Solution {
public:
    static int solve(int n){
        int res=0;
        while(n>0){
            res=(res<<1)|(n&1);
            n>>=1;
        }
        return res;
    }
    static bool compare(int a,int b){
        int x=solve(a);
        int y=solve(b);
        if(x!=y){
            return x<y;
        }
        return a<b;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        return nums;
    }
};