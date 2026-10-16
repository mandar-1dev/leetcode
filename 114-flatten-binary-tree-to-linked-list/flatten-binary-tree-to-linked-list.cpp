
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != NULL) {

            if (root->left != NULL) {
                TreeNode* rightMost = root->left;

                while (rightMost->right != NULL) {
                    rightMost = rightMost->right;
                }

                rightMost->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }

            root = root->right;
        }
    }
};