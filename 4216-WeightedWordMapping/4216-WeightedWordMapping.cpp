// Last updated: 20/07/2026, 10:39:33
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            long long totalWeight = 0;
            for (int j = 0; j < currentWord.length(); j++) {
                char letter = currentWord[j];
                int index = letter - 'a';
                totalWeight += weights[index];
            }
            int remainder = totalWeight % 26;
            char newChar = 'z' - remainder;
            result += newChar;
        }
        return result;
    }
};
