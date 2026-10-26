class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char,int>mp;
        for(char i='A';i<='Z';i++){
            mp[i]=(i-'A')+1;
        }
        int sum=0;
        for(char i:columnTitle){
            sum=(sum*26)+mp[i];
        }
        return sum;
    }
};