/*
Time Complexity: O(h)

We move either left or right using BST property.

Space Complexity: O(1)
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node* successor = NULL;
        
        while(root != NULL) {
            if(root->data > k->data) {
                successor = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
        if(successor == NULL) return -1;
        return successor->data;
    }
};


-----------------------------------------------------------------------------------------

  /*
Time Complexity: O(h)

We search once for predecessor and once for successor.
Total O(2h), which is O(h).

Space Complexity: O(1)
*/

class Solution {
  public:
    Node* succ(Node *root, int key) {
        Node* successor = NULL;
        
        while(root != NULL) {
            if(root->data > key) {
                successor = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
        return successor;
    }
    
    Node* pred(Node *root, int key) {
        Node* predecessor = NULL;
        
        while(root != NULL) {
            if(root->data < key) {
                predecessor = root;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        
        return predecessor;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        return {pred(root, key), succ(root, key)};
    }
};
