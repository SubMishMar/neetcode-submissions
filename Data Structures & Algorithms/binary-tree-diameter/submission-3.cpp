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
    int diameter = 0;
    int maxDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int max_left_depth = maxDepth(root->left);
        int max_right_depth = maxDepth(root->right);
        diameter = std::max(diameter, max_left_depth+max_right_depth);
        return 1+std::max(max_left_depth, max_right_depth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }
};
