/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (!root) return ;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode* tmp = root;
        if (root->left) {
            TreeNode* tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            tmp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
// @lc code=end

 