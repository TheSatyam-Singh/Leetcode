// Last updated: 20/07/2026, 10:38:05
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m,string(n,'#'));
        int row=0;
        int col=0;
        ans[row][col]='.';
        while(row<m-1 || col<n-1){
            if(col<n-1){
                if(col<n-2 || row==m-1){
                    col++;
                }else{
                    row++;
                }
            }else{
                row++;
            }
            ans[row][col]='.';
        }
        return ans;
    }
};