class Solution {
public:
    vector<int>ans;
    Solution(vector<int>& nums) {
        ans=nums;
    }
    
    vector<int> reset() {
        return ans;
    }
    
    vector<int> shuffle() {
        vector<int>res=ans;
        for(int i=res.size()-1;i>0;i--){
            int shuf=rand()%(i+1);
            swap(res[i],res[shuf]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */