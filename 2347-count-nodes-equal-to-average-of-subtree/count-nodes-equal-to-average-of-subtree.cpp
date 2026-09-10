/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    pair<int,int>dfs(TreeNode* root,int &ans){
        if(root==nullptr){
            return {0,0};
        }
        auto [lsum,lcount]=dfs(root->left,ans);
        auto [rsum,rcount]=dfs(root->right,ans);
        int sum=lsum+rsum+root->val;
        int count=lcount+rcount+1;

        if(sum/count == root->val){
            ans++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};