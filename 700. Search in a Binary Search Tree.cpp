/*
Approach 1: Recursive Approach

Time Complexity: O(h)

At every step, we move either to the left subtree or the right subtree
using the Binary Search Tree property.
Here, h is the height of the tree.
In a balanced BST, h = log n.
In a skewed BST, h = n.

Space Complexity: O(h)

Recursion stack can go up to the height of the tree.
In a balanced BST, h = log n.
In a skewed BST, h = n.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == val) {
            return root;
        }

        if(val < root->val) {
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};

--------------------------------------------------------------------------------
/*
Approach 2: Iterative Approach

Time Complexity: O(h)

At every step, we move either to the left subtree or the right subtree
using the Binary Search Tree property.
Here, h is the height of the tree.
In a balanced BST, h = log n.
In a skewed BST, h = n.

Space Complexity: O(1)

No recursion stack or extra data structure is used.
Therefore, the space complexity is O(1).
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL) {
            if(root->val == val) {
                return root;
            }

            if(val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return NULL;
    }
};
