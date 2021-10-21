/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int len = q.size();
            int lastVal = -1;
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                lastVal = node->val;
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            res.emplace_back(lastVal);
        }
        return res;
    }
    // [1,2,3,6,5,null,4,null,1]
};
// @lc code=end

