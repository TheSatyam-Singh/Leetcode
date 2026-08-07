class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int mx=0;
        for(int i:st){
            if(st.find(i-1)==st.end()){
                int count=0;
                while(st.find(i)!=st.end()){
                    count++;
                    i++;
                }
                mx=max(count,mx);
            }
        }
        return mx;
    }
};