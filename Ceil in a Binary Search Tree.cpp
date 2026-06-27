// Time Complexity: O(h)
//
// At every step, we move either left or right using BST property.
// Here, h is the height of the BST.
// In a balanced BST, h = log n.
// In a skewed BST, h = n.

// Space Complexity: O(1)
//
// No recursion stack or extra data structure is used.
// Therefore, space complexity is O(1).


class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        
        while(root != NULL) {
            if(root->data == x) {
                return root->data;
            }
            else if(root->data > x) {
                ceil = root->data;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
        return ceil;
    }
};
