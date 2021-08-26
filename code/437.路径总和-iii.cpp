/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    //参考了答案简洁优雅但是比较慢，以包不包含为划分！
    //todo可以用前缀树等
    int path(TreeNode* root,int targetSum){
        if(!root) return 0;
        //note:这里不能直接返回，还有其他可能
        //if(root->val == targetSum) return 1;
        int res = 0;
        if(root->val == targetSum) ++res;
        res += path(root->left,targetSum-root->val);
        res += path(root->right,targetSum-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        //solution1:错误！存在问题可能出现间断的不正确的解
        /*if(!root) return 0;
        if(!root->left&&!root->right) return (targetSum==root->val);
        return pathSum(root->left,targetSum) + pathSum(root->left,targetSum-root->val)\
        +pathSum(root->right,targetSum)+pathSum(root->right,targetSum-root->val);*/
        //solution2:写的一片混乱，fail
        //solution3:答案写法!!!，将是否包含该节点区分明显
        //以是否包含该节点为切入点划分！！！！为包含和不包含
        //note:混乱的时候不要硬堵，总有更简便优雅的方法！！！
        if(!root) return 0;
        return path(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
    //[10,5,-3,3,2,null,11,3,-2,null,1]\n8
    //[1,2]\n2
    //[0,1,1]\n1
    //[1,null,2,null,3,null,4,null,5]\n3
};
// @lc code=end

