//Approach - 1

/*
Approach: Morris Inorder Traversal

Time Complexity: O(n)

Each node is visited at most a constant number of times while creating
and removing temporary threads.

Space Complexity: O(1)

No recursion stack or extra stack is used.
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int cnt = 0;
        int ans = -1;

        while(curr != NULL) {
            if(curr->left == NULL) {
                cnt++;

                if(cnt == k) {
                    ans = curr->val;
                }

                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;

                while(prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;

                    cnt++;

                    if(cnt == k) {
                        ans = curr->val;
                    }

                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

-----------------------------------------------------------------------------------------------------------

//Approach - 2

/*
Approach: Recursive Inorder Traversal

Time Complexity: O(h + k)

We traverse nodes in inorder until the kth smallest element is found.
In the worst case, all nodes may be visited: O(n).

Space Complexity: O(h)

Recursion stack can go up to the height of the BST.
*/
class Solution {
public:
    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if(root == NULL) return;

        inorder(root->left, k);

        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
