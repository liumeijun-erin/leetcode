/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int help(TreeNode* root, int& res) {
        if(!root) return 0;
        int left_sum = help(root->left, res);
        int right_sum = help(root->right, res);
        //cout<<"root: "<<root->val<<endl;
        //cout<<left_sum<<" "<<right_sum<<endl;
        res += abs(left_sum - right_sum);
        return root->val + left_sum + right_sum;
    }
    int findTilt(TreeNode* root) {
        int res = 0;
        help(root, res);
        return res;
    }
        
};
// @lc code=end

