class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        for(char i:magazine){
            if(mp.find(i)==mp.end()){
                mp[i]=1;
            }else{
                mp[i]++;
            }
        }
        for(char i:ransomNote){
            if(mp.find(i)!=mp.end() && mp[i]>0){
                mp[i]--;
            }else{
                return false;
            }
        }
        return true;
    }
};