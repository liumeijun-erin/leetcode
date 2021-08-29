/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void inorder(TreeNode* root,int& pre,int&res){
        if(!root) return;
        inorder(root->left,pre,res);
        if(pre!= -1){
            res = min(root->val - pre,res);
        }
        pre = root->val;
        inorder(root->right,pre,res); 
    }
    //参考答案：利用本身有序特性直接中序遍历的时候用pre记录
    int getMinimumDifference(TreeNode* root) {
        int res = __INT_MAX__;
        int pre = -1;
        inorder(root,pre,res);
        return res;
    }
};
// @lc code=end

