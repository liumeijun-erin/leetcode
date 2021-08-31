/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* node = root;
        stack<TreeNode*> s;
        while(node){
            s.emplace(node);
            res.emplace_back(node->val);
            node = node->right;
        }
        while(!s.empty()){
            node = s.top();
            s.pop();
            node = node->left;
            while(node){
                s.emplace(node);
                res.emplace_back(node->val);
                node = node->right;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

