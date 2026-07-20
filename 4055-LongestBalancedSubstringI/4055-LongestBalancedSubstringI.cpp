// Last updated: 20/07/2026, 11:23:35
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int len = 0;
        int maxlen = INT_MIN;;
        for(int i=0;i<n;i++) {
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++) {
                mp[s[j]]++;
                bool balanced = true;
                int freq = mp.begin()->second;
                for(auto it : mp) {
                    if(it.second != freq) {
                        balanced = false;
                        break;
                    }
                }
                len = j - i + 1;
                if(balanced) {
                    maxlen = max(maxlen,len);
                }
            }
        } 
        return maxlen;
    }
};