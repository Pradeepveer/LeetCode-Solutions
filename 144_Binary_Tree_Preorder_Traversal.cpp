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
 

// recursive 
void preorder(TreeNode* node, vector<int>& ans){
    if (node == NULL) return;
    ans.push_back(node->val);
    preorder(node->left, ans);
    preorder(node->right, ans);
}


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}



// iterative
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
    if (root == NULL) return ans;

    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        ans.push_back(node->val);
        st.pop();
        if (node->right != NULL) st.push(node->right);
        if (node->left != NULL) st.push(node->left);
    }
    return ans;
}