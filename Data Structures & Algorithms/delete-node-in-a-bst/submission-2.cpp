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
    TreeNode* minValueNode(TreeNode* root) {
        TreeNode* curr = root;
        // Keep moving left to find the smallest value in this subtree
        while(curr != nullptr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base Case: Tree is empty or key doesn't exist in the tree
        if(root == nullptr) {
            return nullptr;
        }

        if(key < root->val) {
            // Target key is smaller, search in left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Target key is larger, search in right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Node to be deleted found!

            // Handles both 0 children (leaf) and 1 child:
            if(root->left == nullptr) {
                // Returns right child (or nullptr if leaf) to parent
                return root->right;
            } else if(root->right == nullptr) {
                // Returns left child to parent
                return root->left;
            } else {
                // Case 3: 2 Children
                // 1. Find in-order successor (min node in right subtree)
                TreeNode* minNode = minValueNode(root->right);
                // 2. Overwrite target node's value with successor's value
                root->val = minNode->val;
                // 3. Delete the duplicate successor from the right subtree
                root->right = deleteNode(root->right, minNode->val);
            }
        }
        return root;
    }
};