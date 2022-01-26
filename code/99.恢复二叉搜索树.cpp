/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    // note1：指针引用
    // note2:由于有[0,1]类样例存在，因此是否!a都要修改b，
    // note3:由于b已经被修改，所以不能以a&&b作为判断终止条件
    void help(TreeNode* root, TreeNode*& a, TreeNode*& b, TreeNode*& pre) {
        if (!root ) return;
        if (root->left) help(root->left, a, b, pre);
        if (pre && root->val < pre->val) {
            if (!a) {
                a = pre;
            }
            b= root;
        }
        pre = root;
        if (root->right) help(root->right, a, b, pre);
    }
    void recoverTree(TreeNode* root) {
       TreeNode* a = nullptr;
       TreeNode* b = nullptr;
       TreeNode* pre = nullptr;
       help(root,a,b,pre);
       int tmp = a->val;
       a->val = b->val;
       b->val = tmp;
    }
};
// @lc code=end

