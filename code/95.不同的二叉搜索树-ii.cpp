/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    //注意树结构vector<TreeNode*>最后不能是一个root 
    //应该复制root结构，不用复制树结构
    vector<TreeNode*> help(int l, int h) {
        if (l > h) return vector<TreeNode*> {nullptr};
        vector<TreeNode*> res;
        for (int i = l;i <= h; ++i) {  
            vector<TreeNode*> left_res = help(l,i-1);
            vector<TreeNode*> right_res = help(i+1,h);
            // cout<<l<<" "<<h<<" "<<i<<endl;
            //cout<<left_res.size()<<" "<<right_res.size()<<endl;
            for (int p = 0; p < left_res.size(); ++p) {
                for (int q = 0; q < right_res.size(); ++q) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_res[p];
                    root->right = right_res[q];
                    res.emplace_back(root);
                }
            }
            //tip: 参考答案，使用& much faster!!!
            // for (auto& left : left_res) {
            //     for (auto& right : right_res) {
            //         TreeNode* currTree = new TreeNode(i);
            //         currTree->left = left;
            //         currTree->right = right;
            //         res.emplace_back(currTree);
            //     }
            // }
            // note：出现问题：指针初始化问题，以后写的时候谨慎一些！
            // 这样写会出现问题：[[1,null,3,2],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
            // for (int p = 0; p < left_res.size(); ++p) {
            //     for (int q = 0; q < right_res.size(); ++q) {
            //         TreeNode* root = new TreeNode(i);  // 这句必须在第二层循环中，可能指针初始化和指针赋值机制不一样，要谨慎
            //         root->left = left_res[p];  //不要拆分，指针初始化和定义最好靠近
            //         root->right = right_res[q];
            //         res.emplace_back(root);
            //     }
            // }
            // 引用也是
            // for (auto& left : left_res) {
            //     TreeNode* currTree = new TreeNode(i);
            //     currTree->left = left;
            //     for (auto& right : right_res) {
            //         currTree->right = right;
            //         res.emplace_back(currTree);
            //     }
            // }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return help(1,n);
    }
    //[[1,null,3,2],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
};
// @lc code=end

