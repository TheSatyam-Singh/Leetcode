// Last updated: 20/07/2026, 10:37:57
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
    int dominant=0;
    int check(TreeNode* root){
        if(!root){
            return INT_MIN;
        }
        int leftmx=check(root->left);
        int rightmx=check(root->right);
        int currentmx=max({root->val,leftmx,rightmx});
        if(root->val==currentmx){
            dominant++;
        }
        return currentmx;
        
    }
    int countDominantNodes(TreeNode* root) {
        dominant=0;
        check(root);
        return dominant;
    }
};