class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int i = 0;
        int count = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') {
                count++;
            }
            while(count>k){
                if(s[i]=='1'){
                    count--;
                }
                i++;
            }
            if (count == k) {
                while (s[i] == '0') {
                    i++;
                }
                string str = s.substr(i, j - i + 1);
                if (ans.empty() || str.size() < ans.size() ||
                    (str.size() == ans.size() && str < ans)) {
                    ans = str;
                }
            }
        }
    return ans;
    }
};