class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int>mp;
        int n=candyType.size()/2;
        for(int i:candyType){
            mp[i]++;
        }
        if(mp.size()<n){
            return mp.size();
        }else{
            return n;
        }
    }
};