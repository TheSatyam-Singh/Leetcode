class Solution {
public:
    bool check(string &str){
        int i=0;
        int j=str.size()-1;
        while(j>i){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int length=j-i+1;
                if(length>k+1){
                    break;
                }
                string temp=s.substr(i,j-i+1);
                if(length>=k && check(temp)){
                    count++;
                    i=j;
                    break;
                }
            }
        }
        return count;
    }
};