// Last updated: 20/07/2026, 11:25:15
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        for(char i = 'a'; i <= 'z'; i++) {
            int lastLower = word.rfind(i);
            int firstUpper = word.find(toupper(i));
            if(lastLower != -1 && firstUpper != -1 && lastLower < firstUpper) {
                count++;
            }
        }
        return count;
    }
};