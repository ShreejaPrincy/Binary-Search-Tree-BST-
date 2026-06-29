/*
Time Complexity: O(n)

Every node is visited once.

Space Complexity: O(h)

Recursion stack is used.
*/

class Solution {
public:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL && prev->val > root->val) {
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;

        inorder(root);

        if(first != NULL && last != NULL) {
            swap(first->val, last->val);
        }
        else if(first != NULL && middle != NULL) {
            swap(first->val, middle->val);
        }
    }
};
