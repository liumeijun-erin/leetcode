/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        queue<TreeNode*> q; 
        q.emplace(root);
        while(!q.empty()){
            int len = q.size();
            ++cnt;
            while(len--){
                TreeNode* n = q.front();
                q.pop();
                if(!n->left&&!n->right) return cnt;
                if(n->left) q.emplace(n->left);
                if(n->right) q.emplace(n->right);
            }
        }
        return cnt;
    }
};
// @lc code=end

