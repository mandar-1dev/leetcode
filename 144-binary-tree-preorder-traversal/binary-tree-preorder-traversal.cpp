class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* current = st.top();
            st.pop();

            ans.push_back(current->val);

            // Right first
            if (current->right)
                st.push(current->right);

            // Left second
            if (current->left)
                st.push(current->left);
        }

        return ans;
    }
};