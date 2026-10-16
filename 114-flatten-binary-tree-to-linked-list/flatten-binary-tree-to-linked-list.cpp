
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        root->left = nullptr;
        root->right = leftSubtree;

        TreeNode* current = root;

        while (current->right != nullptr) {
            current = current->right;
        }

        current->right = rightSubtree;
    }
};
