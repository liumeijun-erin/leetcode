/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        queue<TreeNode*>  q;
        bool right = false;
        q.emplace(root);
        while(!q.empty()){
            vector<int> tmp;
            int len = q.size();
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            if(right) reverse(tmp.begin(),tmp.end());
            res.emplace_back(tmp);
            right = !right;
        }
        return res;
    }
};
// @lc code=end

