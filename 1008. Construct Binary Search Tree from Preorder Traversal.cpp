/*
Time Complexity: O(n)

Each element is used once.

Space Complexity: O(h)

Recursion stack is used.
*/

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int& i, int bound) {
        if(i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        root->left = solve(preorder, i, root->val);
        root->right = solve(preorder, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
};
