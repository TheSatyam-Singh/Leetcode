class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>length(256,-1);
        int left=0;
        int right=0;
        int ans=0;
        while(right<s.size()){
            if(length[s[right]] != -1){
                left=max(left,length[s[right]]+1);
            }
            length[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};


