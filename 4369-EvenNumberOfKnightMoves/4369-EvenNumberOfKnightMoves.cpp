// Last updated: 20/07/2026, 10:37:55
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (start[0]+start[1])%2==(target[0]+target[1])%2;
    }
};