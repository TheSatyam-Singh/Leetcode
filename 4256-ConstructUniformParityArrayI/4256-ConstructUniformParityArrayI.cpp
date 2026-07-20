// Last updated: 20/07/2026, 10:39:11
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odds = 0;
        for (int x : nums) {
            if (x % 2 != 0) odds++;
        }
        bool Even = (odds == 0 || odds >= 2);
        bool Odd = (odds >= 1);
        return Even || Odd;
    }
};