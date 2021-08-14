/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(vector<string> &ans,string& path,TreeNode* node){
        string new_path = path + to_string(node->val);
        if(!node->left && !node->right){
            ans.emplace_back(new_path);
            return ;
        }
        new_path += "->";
        if(node->left) dfs(ans,new_path,node->left);
        if(node->right) dfs(ans,new_path,node->right);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> ans;
        dfs(ans,path,root);
        return ans;
    }
};
// @lc code=end

