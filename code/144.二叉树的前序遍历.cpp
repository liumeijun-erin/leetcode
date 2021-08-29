/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        //solution1:思路加入节点的时候就加入左子树，弹出节点的时候加入右子树
        //note1:加入右子树的时候勿忘右子树的左子树，略麻烦
        //note2:加入左子树的时候需要while
        /*vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.emplace(root);
        res.emplace_back(root->val);
        while(root->left) {
            s.emplace(root->left);
            res.emplace_back(root->left->val);
            root = root->left;
        }
        while(!s.empty()){
            TreeNode* t = s.top();
            s.pop();
            if(t->right){
                t = t->right;
                s.emplace(t);
                res.emplace_back(t->val);
                while(t->left) {
                    s.emplace(t->left);
                    res.emplace_back(t->left->val);
                    t = t -> left;
                }
            }
        }
        return res;*/
        //solution2:更简易想法:往stack里加的时候先右在左
        //结果much better！
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.emplace(root);
        while(!s.empty()){
            TreeNode* t = s.top();
            res.emplace_back(t->val);
            s.pop();
            if(t->right) s.emplace(t->right);
            if(t->left) s.emplace(t->left);
        }
        return res;
    }  
    //[2,3,null,1]
    //[2,null,3,null,1]
};
// @lc code=end

