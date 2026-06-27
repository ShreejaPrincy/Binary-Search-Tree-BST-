/*
Time Complexity: O(h)

We move either left or right at each step.
h = height of BST.
Balanced BST: O(log n)
Skewed BST: O(n)

Space Complexity: O(1)

No extra space is used.
*/

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int floorr = -1;
        
        while(root != NULL) {
            if(root->data == k) {
                return root->data;
            }
            else if(root->data > k) {
                root = root->left;
            }
            else {
                floorr = root->data;
                root = root->right;
            }
        }
        
        return floorr;
    }
};
