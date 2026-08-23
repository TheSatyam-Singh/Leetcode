class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count=0;
        vector<int>freq(10,0);
        for(int i:digits){
            freq[i]++;
        }
        for(int i=0;i<=8;i+=2){
            if(freq[i]==0){
                continue;
            }
            freq[i]--;
            for(int j=1;j<=9;j++){
                if(freq[j]==0){
                    continue;
                }
                freq[j]--;
                for(int k=0;k<=9;k++){
                    if(freq[k]>0){
                        count++;
                    }
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return count;
    }
};