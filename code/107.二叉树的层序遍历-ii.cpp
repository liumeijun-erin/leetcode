/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> tmp;
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            res.emplace_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

