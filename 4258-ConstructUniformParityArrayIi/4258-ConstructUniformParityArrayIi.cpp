// Last updated: 20/07/2026, 10:39:07
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minOdd = INT_MAX;
        for (int x : nums) {
            if (x % 2 != 0) {
                if (x < minOdd) minOdd = x;
            }
        }
        
        bool Even = (minOdd == INT_MAX);
        bool Odd = true;
        for (int x : nums) {
            if (x % 2 == 0) {
                if (minOdd == INT_MAX || minOdd >= x) {
                    Odd = false;
                    break;
                }
            }
        }
        
        return Even || Odd;
    }
};