/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int len = q.size(),num = len;
            double sum = 0;
            while(len--){
                TreeNode* front = q.front();
                q.pop();
                if(front->left) q.emplace(front->left);
                if(front->right) q.emplace(front->right);
                sum += front->val;
            }
            res.emplace_back(sum/num);
        }
        return res;
    }
};
// @lc code=end

