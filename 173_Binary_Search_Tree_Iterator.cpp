#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 


class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);     
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushall(TreeNode* root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }
};