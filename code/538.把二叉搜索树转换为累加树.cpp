/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        root->right = convertBST(root->right);
        TreeNode* node  = root->right;
        if(node) {
            if(node->left){
                while(node->left) node = node->left;
            }
            root->val += node->val;
        }
        node = root->left;
        if(node) {
            if(node->right){
                while(node->right) node = node->right;
            }
            node->val += root->val;
        }
        root->left = convertBST(root->left);
        return root;
    }
};
// @lc code=end

