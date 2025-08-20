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


void inorder(int x, int y, TreeNode* root, map<int, map<int, multiset<int>>>& ds){
    if (root == NULL) return;
    ds[x][y].insert(root->val);

    if (root->left) inorder(x-1, y+1, root->left, ds);
    if (root->right) inorder(x+1, y+1, root->right, ds);
}


vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;

    map<int, map<int, multiset<int>>> ds;
    inorder(0, 0, root, ds); 
    
    for (auto it1 : ds){
        vector<int> col;
        for (auto it2 : it1.second){
            col.insert(col.end(), it2.second.begin(), it2.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}