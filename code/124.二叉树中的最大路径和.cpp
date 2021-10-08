/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int help(TreeNode* root,int& res){
        int sum = root->val;
        int sum_left = 0,sum_right = 0;
        if(root->left) sum_left = help(root->left,res);
        if(sum_left > 0) sum += sum_left;
        if(root->right) sum_right = help(root->right,res);
        if(sum_right > 0) sum += sum_right;
        res = max(sum,res);
        int tmp = max(sum_left,sum_right);
        sum = root->val;
        if(tmp > 0) sum += tmp;
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        help(root,res);
        return res;
    }
    //[5,4,8,11,null,13,4,7,2,null,null,null,1]
};
// @lc code=end

