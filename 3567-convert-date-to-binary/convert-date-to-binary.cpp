class Solution {
public:
    string convert(int a) {
        string binary = "";
        while (a > 0) {
            binary += to_string(a % 2);
            a /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    string convertDateToBinary(string date) {
        string ans = convert(stoi(date.substr(0, 4))) + "-" +
                     convert(stoi(date.substr(5, 2))) + "-" +
                     convert(stoi(date.substr(8, 2)));
        return ans;
    }
};