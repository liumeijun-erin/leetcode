/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    //注意树结构vector<TreeNode*>最后不能是一个root 
    //注意这里：复制root结构即可，不用复制left，right子树结构
    // TreeNode* copy(TreeNode* node) {
    //     if (!node) return nullptr;
    //     TreeNode* res = new TreeNode(node->val);
    //     res->left = copy(node->left);
    //     res->right = copy(node->right);
    //     return res;
    // }
    vector<TreeNode*> help(int left, int right) {
        vector<TreeNode*> res;
        for (int i = left; i <= right; ++i){
            vector<TreeNode*> lTree, rTree;
            if (i != left) lTree = help(left,i-1);
            else lTree.emplace_back(nullptr);
            if (i != right) rTree = help(i+1,right);
            else rTree.emplace_back(nullptr);
            for (TreeNode* lNode: lTree) {
                for (TreeNode* rNode:rTree) {
                    TreeNode* tmp = new TreeNode(i);
                    // tmp->left = copy(lNode);
                    // tmp->right = copy(rNode);
                    tmp->left = lNode;
                    tmp->right = rNode;
                    res.emplace_back(tmp);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return help(1,n);
    }
};
// @lc code=end

