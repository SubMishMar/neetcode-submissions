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
        if(root == nullptr){
            return 0;
        }
        return 1+std::max(maxDepth(root->left), maxDepth(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        int diameter = left_depth+right_depth;
        int sub_tree_diameter = std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return std::max(diameter, sub_tree_diameter);
    }
};
