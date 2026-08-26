class Solution {
public:
    string convert(int n){
        if(n==0){
            return "0";
        }
        string binary="";
        while(n>0){
            binary+=to_string(n%2);
            n/=2;
        }
        reverse(binary.begin(),binary.end());
        return binary;
    }
    int hammingWeight(int n) {
        string ans=convert(n);
        int count=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1'){
                count++;
            }
        }
        return count;
    }
};