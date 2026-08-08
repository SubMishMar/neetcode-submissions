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
    std::vector<std::vector<int>> levels;

    void bfs(TreeNode* root) {
        std::deque<TreeNode*> dq;
        if(root!=nullptr) {
            dq.push_back(root);
        }
        while (dq.size() > 0) {
            int level_size = dq.size();
            std::vector<int> level;
            for (int i = 0; i < level_size; i++) {
                TreeNode* curr = dq.front();
                level.push_back(curr->val);
                dq.pop_front();
                if(curr->left!=nullptr) {
                    dq.push_back(curr->left);
                }
                if(curr->right!=nullptr) {
                    dq.push_back(curr->right);
                } 
            }
            levels.push_back(level);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return levels;
    }
};
