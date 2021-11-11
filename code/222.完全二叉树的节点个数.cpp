/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    vector<int> mul = {1};
public:
    int cntMul(int index) {
        while(index >= mul.size()){
            mul.emplace_back(mul.back()*2);
        }
        //cout<<"index:"<<mul[index]<<endl;
        return mul[index];
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        //cout<<root->val<<endl;
        int h_left = 1,h_right = 1;
        TreeNode* left_node = root;
        TreeNode* right_node = root;
        while (left_node->left) {
            ++h_left;
            left_node = left_node->left; 
        }
        while (right_node->right) {
            ++h_right;
            right_node = right_node->right; 
        }
        if (h_left == h_right) return cntMul(h_left) - 1;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};
// @lc code=end

