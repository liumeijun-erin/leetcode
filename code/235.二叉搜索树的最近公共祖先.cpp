/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p->val > q->val) swap(p,q);
        /*if(root->val >= p->val && root->val <= q->val) return root;
        if(root->val < p->val) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);*/
        while(root){
            if(root->val <= q->val&&root->val >= p->val) break;
            if(root->val < p->val) root = root->right;
            else root = root->left;
        }
        return root;
    }
};
// @lc code=end

