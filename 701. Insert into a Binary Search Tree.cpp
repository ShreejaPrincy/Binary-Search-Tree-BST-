//Approach - 1
/*
Time Complexity: O(h)

We move either left or right at each step.
h = height of BST.
Balanced BST: O(log n)
Skewed BST: O(n)

Space Complexity: O(h)

Recursion stack can go up to height of BST.
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }

        if(val<=root->val){
            TreeNode* node=insertIntoBST(root->left,val);
            root->left=node;
        }
        else{
            TreeNode* node=insertIntoBST(root->right,val);
            root->right=node;
        }

        return root;
    }
};

---------------------------------------------------------------
//Approach - 1

/*
 Iterative Approach

Time Complexity: O(h)

We move either left or right at each step.
h = height of BST.
Balanced BST: O(log n)
Skewed BST: O(n)

Space Complexity: O(1)

No recursion stack is used.
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }

        TreeNode* curr = root;

        while(true) {
            if(val < curr->val) {
                if(curr->left == NULL) {
                    curr->left = new TreeNode(val);
                    break;
                }
                curr = curr->left;
            }
            else {
                if(curr->right == NULL) {
                    curr->right = new TreeNode(val);
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};
