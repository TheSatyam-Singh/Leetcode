// Last updated: 20/07/2026, 11:25:24
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for(int num : arr1) {
            while(num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }
        int ans = 0;
        for(int num : arr2) {
            int x = num;
            int len = 0;
            int temp = num;
            while(temp > 0) {
                len++;
                temp /= 10;
            }
            while(x > 0) {
                if(prefixes.count(x)) {
                    ans = max(ans, len);
                    break;
                }
                x /= 10;
                len--;
            }
        }
        return ans;
    }
};