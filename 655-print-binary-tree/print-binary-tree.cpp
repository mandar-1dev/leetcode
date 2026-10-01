class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void solve(TreeNode* root, vector<vector<string>>& ans,
               int row, int left, int right) {

        if (root == nullptr)
            return;

        int mid = (left + right) / 2;

        ans[row][mid] = to_string(root->val);

        solve(root->left, ans, row + 1, left, mid - 1);
        solve(root->right, ans, row + 1, mid + 1, right);
    }

    vector<vector<string>> printTree(TreeNode* root) {

        int h = height(root);

        int rows = h;
        int cols = (1 << h) - 1;

        vector<vector<string>> ans(rows, vector<string>(cols, ""));

        solve(root, ans, 0, 0, cols - 1);

        return ans;
    }
};