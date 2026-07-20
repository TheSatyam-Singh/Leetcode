// Last updated: 20/07/2026, 11:25:23
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int column=matrix[0].size();
        for(int j=0;j<column;j++){
            int mx=INT_MIN;
            for(int i=0;i<rows;i++){
                if (matrix[i][j]!=-1){
                    mx=max(mx,matrix[i][j]);
                }
            }
            for(int i=0;i<rows;i++){
                if (matrix[i][j]==-1){
                    matrix[i][j]=mx;
                }
            }
        }
        return matrix;
    }
};