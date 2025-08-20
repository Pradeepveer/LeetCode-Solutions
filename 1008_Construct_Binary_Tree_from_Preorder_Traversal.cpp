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


TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}


TreeNode* build(vector<int>& preorder, int& i, int bound){
    if (i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preorder[i++]);

    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);
    return root;
}


// 0ms soln
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root=new TreeNode(preorder[0]);
    for(int i=1;i<preorder.size();i++){
        int x=preorder[i];
        TreeNode* temp=root;
        TreeNode* prev=temp;
        int p=0;
        while(temp!=NULL){
            if(temp->val>x){
                prev=temp;
                temp=temp->left;
                p=1;
            }else{
                prev=temp;
                temp=temp->right;
                p=2;
            }
        }
        if(p==0)return new TreeNode(x);
        else if(p==1){
            prev->left=new TreeNode(x);
        }else{
            prev->right=new TreeNode(x);
        }
    }
    return root;
}