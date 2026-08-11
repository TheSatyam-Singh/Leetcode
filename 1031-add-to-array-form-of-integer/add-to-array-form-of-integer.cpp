class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            int sum=num[i]+k%10;
            k/=10;
            if(sum>=10){
                k++;
                sum-=10;
            }
            ans.push_back(sum);
        }
        while(k>0){
            ans.push_back(k%10);
            k/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;   
    }
};