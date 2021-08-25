/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        //solution1:bfs写法
        /*if(!root) return 0;
        queue<TreeNode*> q;
        q.emplace(root);
        int res = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            ++res;
        }
        return res;*/
        //solution2:递归写法，参考答案：
        if(!root) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
// @lc code=end

