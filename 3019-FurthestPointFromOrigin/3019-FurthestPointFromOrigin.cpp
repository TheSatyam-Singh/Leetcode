// Last updated: 20/07/2026, 11:25:35
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0;
        int right=0;
        int space=0;
        for (int i=0;i<moves.length();i++){
            if (moves[i]=='L'){
                left++;
            }
            if (moves[i]=='R'){
                right++;
            }
            if (moves[i]=='_'){
                space++;
            }
        }
        if (left>right){
            left+=space;
        }else{
            right+=space;
        }
        return abs((left*-1)+(right*1));   
    }
};