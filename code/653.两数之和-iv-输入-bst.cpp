/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    void inorder(unordered_set<int>& s,TreeNode* root,int k,bool& find){
        if(!root||find) return;
        inorder(s,root->left,k,find);
        if(s.count(root->val)) {
            find = true;
            return;
        }
        else{
            if(k-root->val<=10000&&k-root->val>=-10000){
                s.insert(k-root->val);
            }
        }
        inorder(s,root->right,k,find);
    }
    bool findTarget(TreeNode* root, int k) {
        if(k >20000||k<-20000) return false;
        unordered_set<int> s;
        bool find = false;
        inorder(s,root,k,find);
        return find;
    }
};
// @lc code=end

