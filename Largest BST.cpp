/*
Time Complexity: O(n)

Every node is visited once.

Space Complexity: O(h)

Recursion stack is used.
*/


class NodeValue {
public:
    int minNode;
    int maxNode;
    int maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue solve(TreeNode* root) {
        if(root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        if(left.maxNode < root->val && root->val < right.minNode) {
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.maxSize, right.maxSize)
        );
    }

    int largestBSTSubtree(TreeNode* root) {
        return solve(root).maxSize;
    }
};
