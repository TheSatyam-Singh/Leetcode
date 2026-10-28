class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string>banset(banned.begin(),banned.end());
        for(char &i:paragraph){
            if(isalpha(i)){
                i=tolower(i);
            }else{
                i=' ';
            }
        }
        unordered_map<string,int>count;
        stringstream ss(paragraph);
        string word;
        string mxword;
        int mxcount=0;
        while(ss>>word){
            if (banset.find(word)==banset.end()){
                count[word]++;
                if(count[word]>mxcount){
                    mxcount=count[word];
                    mxword=word;
                }
            }
        }
        return mxword;
    }
};