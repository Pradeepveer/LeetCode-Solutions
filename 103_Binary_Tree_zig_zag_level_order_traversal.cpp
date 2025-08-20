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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> st;
    if (root == NULL) return ans;

    bool left = true;
    st.push(root);
    while(!st.empty()){
        int size = st.size();
        vector<int> level;
        
        for (int i=0; i<size; i++){
            TreeNode* node = st.front();
            st.pop();
            level.push_back(node->val);
            if (node->left != NULL) st.push(node->left);
            if (node->right != NULL) st.push(node->right);    
        }

        if (left == true) ans.push_back(level);
        else{
            reverse(level.begin(), level.end());
            ans.push_back(level);
        }
        left = !left;

    }
    return ans;
}