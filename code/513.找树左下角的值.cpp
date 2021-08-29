/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int num;
        while(!q.empty()){
            int len = q.size();
            num = q.front()->val;
            while(len--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
        }
        return num;
    }
};
// @lc code=end

