/*
LeetCode 450. Delete Node in a BST

Approach: Iterative Approach

Time Complexity: O(h)

We search the node using BST property.
In the two-child case, we find the rightmost node of left subtree.
Here, h is the height of BST.

Space Complexity: O(1)

No recursion stack or extra data structure is used.
*/

class Solution {
public:
    TreeNode* findRightMost(TreeNode* root) {
        while(root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteHelper(TreeNode* root) {
        if(root->left == NULL) {
            return root->right;
        }

        if(root->right == NULL) {
            return root->left;
        }

        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        TreeNode* rightMostNode = findRightMost(leftSubtree);
        rightMostNode->right = rightSubtree;

        return leftSubtree;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {
            return deleteHelper(root);
        }

        TreeNode* curr = root;

        while(curr != NULL) {
            if(key < curr->val) {
                if(curr->left != NULL && curr->left->val == key) {
                    curr->left = deleteHelper(curr->left);
                    break;
                }
                curr = curr->left;
            }
            else {
                if(curr->right != NULL && curr->right->val == key) {
                    curr->right = deleteHelper(curr->right);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};
