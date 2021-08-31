/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //solution1:递归回溯，记录path然后找公共前缀
    /*void collectPath(TreeNode* root,TreeNode* p,TreeNode* q,vector<int> &pathp,vector<int> &pathq,vector<int>&path){
        if(!root) return ;
        if(!pathp.empty()&&!pathq.empty()) return;
        if(root == p) pathp = path;
        else if(root == q) pathq = path;
        path.emplace_back(0);
        collectPath(root->left,p,q,pathp,pathq,path);
        path[path.size()-1] = 1;
        collectPath(root->right,p,q,pathp,pathq,path);
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //failed-solution1：试图用dfs写出每个节点的path失败
        vector<int> pathp,pathq,path;
        collectPath(root,p,q,pathp,pathq,path);
        TreeNode* node = root;
        for(int i = 0;i < pathp.size()&&i < pathq.size();++i){
            if(pathp[i]!=pathq[i]) break;
            if(pathp[i])  node = node->right;
            else node = node->left;
        }
        return node;
    }*/
    //solution2:递归实现
    //捋清边界应该是有一个是p/q
    //参考答案!!!
    //！！！note:过程中可以返回结果可以不同含义，只要函数最后输出是正确结果即可！！！
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root == p||root == q) return root;
        //note1：弄清边界条件！
        //note2：想清楚左右子树和总结果的关系，没有的话不返回nullptr,而是返回root！！！
        TreeNode* leftRes = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightRes = lowestCommonAncestor(root->right,p,q);
        if(leftRes&&rightRes) return root;
        else if(leftRes) return leftRes;
        return rightRes;
    }
    //[1,2]\n2\n1
    //[3,5,1,6,2,0,8,null,null,7,4]\n5\n4
};
// @lc code=end

