// Last updated: 20/07/2026, 11:26:10
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>freqofs(128,0);
        vector<int>freqoftarget(128,0);
        for(char i:s){
            freqofs[i]++;
        }
        for(char i:target){
            freqoftarget[i]++;
        }
        int count=INT_MAX;
        for(int i=0;i<target.size();i++){
            count=min(count,freqofs[target[i]]/freqoftarget[target[i]]);
        }
        return count;
    }
};