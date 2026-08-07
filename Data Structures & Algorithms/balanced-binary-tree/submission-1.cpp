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
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root,res);
        return res;
    }

    int dfs(TreeNode* root, bool& res){
        if(!root){
            return 0;
        }

        int leftHeight = dfs(root->left,res);
        int rightHeight = dfs(root->right,res);
        if(abs(leftHeight-rightHeight)>1){
            res=false;
        }
        // cout<<leftHeight<<" - "<<rightHeight<<" - "<<res<<endl;
        return 1+max(leftHeight,rightHeight);
    }
};
