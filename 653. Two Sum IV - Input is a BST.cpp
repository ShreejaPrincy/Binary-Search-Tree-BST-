/*
Time Complexity: O(n)

Each node is pushed and popped at most once.

Space Complexity: O(h)

Two stacks store tree paths.
*/

class Solution {
private:
    stack<TreeNode*> nextSt;
    stack<TreeNode*> beforeSt;

public:
    void pushAllNext(TreeNode* root) {
        while(root != NULL) {
            nextSt.push(root);
            root = root->left;
        }
    }

    void pushAllBefore(TreeNode* root) {
        while(root != NULL) {
            beforeSt.push(root);
            root = root->right;
        }
    }

    int nextCall() {
        TreeNode* node = nextSt.top();
        nextSt.pop();

        pushAllNext(node->right);

        return node->val;
    }

    int beforeCall() {
        TreeNode* node = beforeSt.top();
        beforeSt.pop();

        pushAllBefore(node->left);

        return node->val;
    }

    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        pushAllNext(root);
        pushAllBefore(root);

        int i = nextCall();      // smallest
        int j = beforeCall();    // largest

        while(i < j) {
            int sum = i + j;

            if(sum == k) return true;
            else if(sum < k) {
                i = nextCall();
            }
            else {
                j = beforeCall();
            }
        }

        return false;
    }
};
