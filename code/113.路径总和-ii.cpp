/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void dfs(vector<vector<int> >& res,TreeNode* root,int targetSum,vector<int>& path){
        path.emplace_back(root->val);
        if(!(root->left)&&!(root->right)){
            if(root->val == targetSum) res.emplace_back(path);
            path.pop_back();
            return;
        }
        targetSum -= root->val;
        if(root->left) dfs(res,root->left,targetSum,path);
        if(root->right) dfs(res,root->right,targetSum,path);
        path.pop_back();
        targetSum += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > res;
        if(!root) return res;
        vector<int> path;
        dfs(res,root,targetSum,path);
        return res;
    }
};
// @lc code=end

