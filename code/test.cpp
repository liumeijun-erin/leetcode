#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

bool issym(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    else if (!left || !right) return false;
    if (left->val == right->val) return issym(left->right, right->left) && issym(left->left, right->right);
    return false;
}

bool issym_tree(TreeNode* root) {
    if (!root) return true;
    return issym(root->left, root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout<<issym_tree(root)<<endl;
    return 0;
}