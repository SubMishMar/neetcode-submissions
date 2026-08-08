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
        // store root in a separate pointer so as not to 
        // modify root.
        TreeNode* curr = root;
        // Go on as long as your current node and its left children 
        // are not null.
        while(curr != nullptr && curr->left !=nullptr) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) {
            // Case 0 - no children so return nullptr
            return nullptr;
        }

        if(key < root->val) {
            // go left if value to be deleted is bigger
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // go right if value to be deleted is smaller
            root->right = deleteNode(root->right, key);
        } else {
            // Now we have found the value
            if(root->left == nullptr) {
                // if you hit null when going left, go right
                // Case 1 - 1 Child
                return root->right;
            } else if(root->right == nullptr) {
                // if you hit null when going right, go left
                // Case 1 - 1 Child
                return root->left;
            } else {
                // Case 3 - 2 Children
                // 1. Find the min node from the left sub-tree
                TreeNode* minNode = minValueNode(root->right);
                // 2. Set the target's value to the value at minNode
                root->val = minNode->val;
                // 3. Delete the node with repeated value.
                root->right = deleteNode(root->right, minNode->val);
            }
        }
        return root;
    }
};