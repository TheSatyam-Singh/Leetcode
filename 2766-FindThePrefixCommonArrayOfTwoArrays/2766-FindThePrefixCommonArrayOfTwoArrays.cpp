// Last updated: 20/07/2026, 10:52:37
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        for (int i=0;i<A.size();i++){
            int count=0;
            for(int j=0;j<=i;j++){
                if (find(B.begin(),B.begin()+i+1,A[j])!=B.begin()+i+1){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};