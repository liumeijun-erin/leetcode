/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        int even_layer = 1;
        int pre = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int len = q.size();
            if (even_layer) pre = 0;
            else pre = 1000001;
            while(len--) {
                TreeNode* node = q.front();
                q.pop();
                if (even_layer != node->val % 2) return false;
                if (even_layer && node->val <= pre || !even_layer && node->val >= pre) return false;
                pre = node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            even_layer = 1 - even_layer;
        }
        return true;
    }
};
// @lc code=end

