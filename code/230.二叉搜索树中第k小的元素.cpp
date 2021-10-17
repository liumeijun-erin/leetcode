/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int help(TreeNode* root,int& k){
        int res = -1;
        if(root->left) res = help(root->left,k);
        if(res != -1) return res;
        if(k == 1) return root->val;
        --k;
        if(root->right) res = help(root->right,k);
        else return -1;
        return res;
    }
    int kthSmallest(TreeNode* root, int k) {
        return help(root,k);
    }
};
// @lc code=end

