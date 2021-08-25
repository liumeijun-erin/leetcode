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
    //tip：参考答案使用balance标记提前结束递归
    int maxHeight(TreeNode* root,bool& balance){
        if(!balance||!root) return 0;
        int left = maxHeight(root->left,balance);
        int right = maxHeight(root->right,balance);
        if(abs(left-right) > 1) balance = false;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        maxHeight(root,balance);
        return balance;
    }
};
// @lc code=end

