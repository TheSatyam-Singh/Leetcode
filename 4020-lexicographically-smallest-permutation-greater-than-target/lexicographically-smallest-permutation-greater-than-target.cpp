class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>total(26,0);
        for(char i:s){
            total[i-'a']++;
        }
        vector<int>used(26,0);
        int i=0;
        while(i<n){
            int c=target[i]-'a';
            if(used[c]==total[c]){
                break;
            }
            used[c]++;
            i++;
        }
        while(i>=0){
            if(i<n){
                int current=target[i]-'a';
                for(int j=current+1;j<26;j++){
                    if(used[j]==total[j]){
                        continue;
                    }
                    string ans=target.substr(0,i);
                    ans+=char('a'+j);
                    for(int c=0;c<26;c++){
                        int remain=total[c]-used[c];
                        if(c==j){
                            remain--;
                        }
                        ans+=string(remain,char('a'+c));
                    }
                    return ans;
                }
            }
            if(i>0){
                used[target[i-1]-'a']--;
            }
            i--;
        }
        return "";
    }
};