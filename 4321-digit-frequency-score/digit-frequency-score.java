class Solution {
    public int digitFrequencyScore(int n) {
        int freq[] = new int[10];
        int temp=n;
        while(temp>0){
            int digit = temp % 10;
            freq[digit]++;
            temp /= 10; 
        }
        int totalScore=0;
        for(int i=0;i<=9;i++){
            if(freq[i]>0){
                totalScore+=i*freq[i];
            }
        }
        return totalScore;
    }
}