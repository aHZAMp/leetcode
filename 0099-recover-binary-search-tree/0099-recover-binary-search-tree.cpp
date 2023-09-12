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
    vector<int>inorder;
   
    void traverse(TreeNode* root)
    {
        if(root==NULL)
            return ;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
    void recoverBST(TreeNode* root,int &i)
    {
        if(root==NULL)
            return ;
        recoverBST(root->left,i);
        if(inorder[i]!=root->val)
            root->val=inorder[i];
        i++;
        recoverBST(root->right,i);
    }
    void recoverTree(TreeNode* root) {
        
       traverse(root);
        sort(inorder.begin(),inorder.end());
        int i=0;
        recoverBST(root,i);
        
    }
};