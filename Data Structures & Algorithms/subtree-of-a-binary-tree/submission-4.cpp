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
    bool isSametree(TreeNode* tree1, TreeNode* tree2) {
        if(tree1==nullptr && tree2==nullptr){
            return true;
        }
        if(tree1!=nullptr && tree2!=nullptr && tree1->val == tree2->val){
            return isSametree(tree1->left, tree2->left) && 
                   isSametree(tree1->right, tree2->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr){
            return true;
        }
        if(subRoot == nullptr){
            return true;
        }
        if(root == nullptr){
            return false;
        }

        if(isSametree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
