/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    //solution1-超时：计算help越级，有重复计算;
    //solution1.5-参考答案:选择使用hashmap保存中间结果优化！！！这样实现树结构的动态规划
    //!!!通过unordered_map<TreeNode*,int> 实现树的动态规划
    /*int help(TreeNode* root,unordered_map<TreeNode*,int>& hash){
        if(hash.count(root)) return hash[root];
        int res1 = 0;
        int res2 = 0;
        if(root->left){
            res2 += help(root->left,hash);
            if(root->left->left)  res1 += help(root->left->left,hash);
            if(root->left->right)  res1 += help(root->left->right,hash);
        }
        if(root->right){
            res2 += help(root->right,hash);
            if(root->right->left)  res1 += help(root->right->left,hash);
            if(root->right->right)  res1 += help(root->right->right,hash);
        }
        res1 += root->val;
        hash[root] = max(res1,res2);
        return hash[root];
        
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*,int> hash;
        help(root,hash);
        return hash[root];
    }*/
    //solution2:参考答案，增加变量用于明确当前子节点到底取不取的状态!,res1和res2并行处理
    pair<int,int> help(TreeNode* root){
        pair<int,int> res(0,0),res1(0,0),res2(0,0);
        if(root->left) res1 = help(root->left);
        if(root->right) res2 = help(root->right);
        res.first = root->val + res1.second+res2.second;
        //int tmp =  max(res1.first+res2.first,res1.first+res2.second);
        //res.second = max(tmp,res1.second+res2.first);
        //note1:这里写法勿忘可以都不偷！！！因为动态规划要往上考虑，存在父子子都不偷的最优解情况！
        res.second = max(res1.first,res1.second) + max(res2.first,res2.second);
        return res;
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        pair<int,int> res = help(root);
        return max(res.first,res.second);
    }
    //超时[79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null]
};
// @lc code=end

