/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    void createTree(TreeNode*& cur,TreeNode* root){
        if(!root) return;
        TreeNode* node = root;
        node = root->left;
        createTree(cur,root->left);
        root->left = nullptr;
        cur->right = root;
        cur = root;
        createTree(cur,root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(),*cur = dummy;
        createTree(cur,root);
        return dummy->right;
    }
};
// @lc code=end

