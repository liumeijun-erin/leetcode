/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* build(vector<int> & preorder,vector<int>&inorder,int p1,int p2,int i1,int i2){
        //solution2:原地存索引和数组
        if(p1 == p2) return nullptr;
        TreeNode* root = new TreeNode(preorder[p1]);
        if(p2-p1==1) return root;
        int i;
        for(i = i1;i < i2;++i){
            if(inorder[i] == preorder[p1]) break;
        }
        root->left = build(preorder,inorder,p1+1,p1+1+i-i1,i1,i);
        root->right = build(preorder,inorder,p1+1+i-i1,p2,i+1,i2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //solution1:有很多数组复制操作
        /*if(preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return root;
        vector<int>::iterator it;
        for(it = inorder.begin();it!=inorder.end();++it){
            if((*it) == root->val) break;
        }
        vector<int> left_inorder(inorder.begin(),it);
        inorder.erase(inorder.begin(),it+1);
        vector<int> left_preorder(preorder.begin()+1,preorder.begin()+left_inorder.size()+1);
        preorder.erase(preorder.begin(),preorder.begin()+left_inorder.size()+1);
        root->left = buildTree(left_preorder,left_inorder);
        root->right = buildTree(preorder,inorder);
        return root;*/
        //solution2:直接在原地传数组索引
        return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
};
// @lc code=end

