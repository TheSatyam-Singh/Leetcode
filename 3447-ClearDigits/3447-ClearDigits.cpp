// Last updated: 20/07/2026, 11:25:06
class Solution {
public:
    string clearDigits(string s) {
        string res="";
        for (char i:s) {
            if (isdigit(i)){
                if (!res.empty()) {
                    res.pop_back();
                }
            } else {
                res.push_back(i);
            }
        }
        return res;
    }
};
