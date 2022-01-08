/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int balancedHeight(TreeNode* node) {
        if (!node) return 0;
        int left_h = balancedHeight(node->left);
        int right_h = balancedHeight(node->right);
        if (left_h == -1 || right_h == -1 || abs(left_h - right_h) > 1) return -1;
        return max(left_h, right_h) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return (balancedHeight(root) != -1);
    }
};
// @lc code=end

