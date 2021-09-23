/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    void dfs(int& res,TreeNode* root,int tmp){
        if(!(root->left)&&!(root->right)){
            res += 10*tmp+root->val;
        }
        else{
            if(root->left) dfs(res,root->left,10*tmp+root->val);
            if(root->right) dfs(res,root->right,10*tmp+root->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        //note:不可以层次遍历，注意10+2+3！=12+13
        int res = 0;
        if(!root) return res;
        dfs(res,root,0);
        return res;
    }
};
// @lc code=end

