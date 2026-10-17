
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int n = q.size();
            bool foundX = false, foundY = false;
            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;

            for (int i = 0; i < n; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) {
                    foundX = true;
                    parentX = parent;
                }

                if (node->val == y) {
                    foundY = true;
                    parentY = parent;
                }

                if (node->left)
                    q.push({node->left, node});

                if (node->right)
                    q.push({node->right, node});
            }

            if (foundX || foundY) {
                return foundX && foundY && parentX != parentY;
            }
        }

        return false;
    }
};
