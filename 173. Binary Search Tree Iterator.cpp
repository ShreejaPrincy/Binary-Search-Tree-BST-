/*
Time Complexity:

next(): O(1) average
hasNext(): O(1)

Overall, each node is pushed and popped only once.

Space Complexity: O(h)

Stack stores left path nodes.
Balanced BST: O(log n)
Skewed BST: O(n)
*/

class BSTIterator {
private:
    stack<TreeNode*> st;

public:
    void pushAll(TreeNode* root) {
        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();

        pushAll(node->right);

        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
