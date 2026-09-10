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
    int calculateAverage(int sum, int count) {
        return sum / count;
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        stack<TreeNode*> st;
        stack<TreeNode*> order;

        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            order.push(node);

            if (node->left != nullptr) {
                st.push(node->left);
            }

            if (node->right != nullptr) {
                st.push(node->right);
            }
        }

        unordered_map<TreeNode*, pair<int, int>> data;

        while (!order.empty()) {
            TreeNode* node = order.top();
            order.pop();

            int sum = node->val;
            int count = 1;

            if (node->left != nullptr) {
                sum += data[node->left].first;
                count += data[node->left].second;
            }

            if (node->right != nullptr) {
                sum += data[node->right].first;
                count += data[node->right].second;
            }

            int avg = calculateAverage(sum, count);

            if (avg == node->val) {
                ans++;
            }

            data[node] = {sum, count};
        }

        return ans;
        
    }
};