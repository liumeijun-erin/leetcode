/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool help(bool& started,int& cur_max,TreeNode* root){
        if(root->left&&!help(started,cur_max,root->left)) return false;
        if(started&&cur_max >=  root->val) return false;
        cur_max = root->val;
        started = true;
        if(root->right&&!help(started,cur_max,root->right)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        bool started = false;
        int cur_max = -1;
        return help(started,cur_max,root);
    }
};
// @lc code=end

