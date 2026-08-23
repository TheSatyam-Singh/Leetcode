class Solution {
public:
    int hashCode(char c){
        if(c=='A'){
            return 1;
        }
        if(c=='C'){
            return 2;
        }
        if(c=='G'){
            return 3;
        }
        else{
            return 4;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<long long,int>mp;
        int base=5;
        int power=1;
        int hash=0;
        for(int i=1;i<10;i++){
            power=power*base;
        }
        for(int i=0;i<10;i++){
            hash=hash*base+hashCode(s[i]);
        }
        mp[hash]++;
        for(int i=10;i<s.size();i++){
            hash=hash-(hashCode(s[i-10])*power);
            hash=hash*base;
            hash+=hashCode(s[i]);
            mp[hash]++;
            if(mp[hash]==2){
                ans.push_back(s.substr(i-9,10));
            }
        }
        return ans;
    }
};