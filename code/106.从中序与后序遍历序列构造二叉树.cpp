/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder,int in1,int in2,int post1, int post2){
        if(in1 > in2) return nullptr;
        TreeNode* root = new TreeNode(postorder[post2]);
        if(in1 == in2) return root;
        int i;
        for(i = in1;i <= in2;++i){
            if(postorder[post2] == inorder[i]) break;
        }
        root->left = constructTree(inorder,postorder,in1,i-1,post1,post1+i-1-in1);
        root->right = constructTree(inorder,postorder,i+1,in2,post2+i-in2,post2-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return constructTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
// @lc code=end

