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
    //参考答案：利用中序遍历二叉查找树结果有序!!!
    //且要利用好给定的两者互换的关系，不用大范围remove/insert
    //note:巧妙定义异常：序列中比前一个小的；如果有两个则交换第二个和第一个的前一个，如果有一
    //tip：这里记录前一个的pre应该用TreeNode*类型！！！这样就不用二次遍历改结构
    //参考答案提示：可能有两种情况-一种异常，这是调换的两个值肯定相邻!!!--两种异常，这时记录两个指针对调值即可
    void inorder(TreeNode* root,TreeNode*& pre,TreeNode*& n1,TreeNode*& n2){
        if(!root) return ;
        inorder(root->left,pre,n1,n2);
        if(pre&&root->val < pre->val){
            //cout<<"error"<<endl;
            if(n1){
                n1 = root;   
                //stop = true; 
                //cout<<n1->val<<" "<<n2->val<<endl;
            }
            else{
                n1 = root;
                n2 = pre;
                //cout<<n1->val<<" "<<n2->val<<endl;
            }
        }
        pre = root;
        inorder(root->right,pre,n1,n2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* n1 = nullptr,*n2 = nullptr,*pre = nullptr;
        inorder(root,pre,n1,n2);
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
};
// @lc code=end

