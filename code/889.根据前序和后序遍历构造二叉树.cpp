/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder,int pre1,int pre2,int post1, int post2){
        TreeNode* root = new TreeNode(preorder[pre1]);
        if(pre1 == pre2) return root;
        int i;
        for(i = post1;i <= post2;++i){
            if(postorder[i] == preorder[pre1+1]) break;
        }
        //note:考虑只有左子树/右子树情况!
        if(i == post2 - 1){
            TreeNode* tmp = constructTree(preorder,postorder,pre1+1,pre2,post1,i);
            if(preorder[pre1+1] > preorder[pre1]) root->right = tmp;
            else root->left = tmp;
        }
        else{
            root->left = constructTree(preorder,postorder,pre1+1,pre1+1+i-post1,post1,i);
            root->right = constructTree(preorder,postorder,pre1+2+i-post1,pre2,i+1,post2-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       return constructTree(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }
    //[2,1]\n[1,2]
};
// @lc code=end

