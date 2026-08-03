class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>ans;
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
        return mx;
    }
};


