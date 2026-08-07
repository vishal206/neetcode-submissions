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
    int maxDepth(TreeNode* root) {
        int leftD=0,rightD=0;
        if(root== nullptr){
            return 0;
        }
        if(root->left){
            leftD=maxDepth(root->left);
        }
        if (root->right){
            rightD=maxDepth(root->right);
        }

        return 1+max(leftD,rightD);
    }
};
