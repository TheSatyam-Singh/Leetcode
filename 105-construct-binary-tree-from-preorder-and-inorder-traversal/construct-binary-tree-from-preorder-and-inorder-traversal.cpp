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
    unordered_map<int,int>mp;
    int idx=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder, inorder, 0, inorder.size()-1);
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder, int left, int right){
        if(left>right){
            return NULL;
        }
        int rootv=preorder[idx++];
        TreeNode* root=new TreeNode(rootv);
        int mid=mp[rootv];
        root->left=solve(preorder,inorder,left,mid-1);
        root->right=solve(preorder,inorder,mid+1,right);
        return root;
    }
};