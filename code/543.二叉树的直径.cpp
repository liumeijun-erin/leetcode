/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int maxHeight(TreeNode* root,int& diameter){
        if(!root) return 0;
        int left = maxHeight(root->left,diameter);
        int right = maxHeight(root->right,diameter);
        //cout<<root->val<<" "<<left<<" "<<right<<endl;
        diameter = max(diameter,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter = 0;
        maxHeight(root,diameter);
        return diameter;
    }
};
// @lc code=end

