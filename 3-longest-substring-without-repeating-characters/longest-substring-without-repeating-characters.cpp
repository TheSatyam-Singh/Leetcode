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
        /*vector<char>ans;
        int l=0;
        int mx=0;
        for(int i=0;i<s.size();i++){
            while (find(ans.begin(),ans.end(), s[i]) != ans.end()) {
                ans.erase(find(ans.begin(),ans.end(),s[l]));
                l++;
            }
            ans.push_back(s[i]);
            mx=max(mx,i-l+1);
        }
        return mx;*/
    }
};


