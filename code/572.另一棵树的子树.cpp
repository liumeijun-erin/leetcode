/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool same(TreeNode* root,TreeNode* subRoot){
        if(!root&&!subRoot) return true;
        if(!root||!subRoot) return false;
        if(root->val != subRoot->val) return false;
        return same(root->left,subRoot->left)&&same(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root&&!subRoot) return true;
        if(!root||!subRoot) return false;
        if(root->val == subRoot->val&&same(root,subRoot))  {
            return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
    //[1,1]\n[1]
    //[-1,-4,8,-6,-2,3,9,null,-5,null,null,0,7]\n[3,0,5848]

};
// @lc code=end

