/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            TreeNode* node,*new_root;
            if(root->left){
                node = root->left;
                if(node->right){
                    while(node->right&&node->right->right) node = node->right;
                    new_root = node->right;
                    node->right = new_root->left;
                    new_root->left = root->left;
                }
                else{
                    new_root = node;
                }
                new_root->right = root->right;
                delete root;
                root = new_root;
            } 
            else if(root->right){
                node = root->right;
                if(node->left){
                    while(node->left&&node->left->left) node = node->left;
                    new_root = node->left;
                    node->left = new_root->right;
                    new_root->right = root->right;
                }
                else{
                    new_root = node;
                }
                new_root->left = root->left;
                delete root;
                root = new_root;
            }
            else {
                delete root;
                root = nullptr;
            }
        }
        else if(root->val < key) root->right = deleteNode(root->right,key);
        else root->left = deleteNode(root->left,key);
        return root;
    }
};
// @lc code=end

