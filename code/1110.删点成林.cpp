/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //solution1:
        //todo:本方法要考虑边界条件太多，
        //递归写法much easier
        /*vector<TreeNode*> res;
        if(!root) return res;
        queue<TreeNode*> q;
        unordered_set<int> s;
        for(const int x:to_delete){
            s.emplace(x);
        }
        if(!s.count(root->val)){
            res.emplace_back(root);
            q.emplace(root);
        }
        else{
            queue<TreeNode*> qq;
            qq.emplace(root);
            while(!qq.empty()){
                TreeNode* node = qq.front();
                qq.pop();
                if(s.count(node->val)){
                    s.erase(node->val);
                    if(node->left) qq.emplace(node->left);
                    if(node->right) qq.emplace(node->right);
                }
                else{
                    q.emplace(node);
                    res.emplace_back(node);
                }
            }
        }
        while(!s.empty()&&!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            int x ;
            if(node->left){
                x = node->left->val;
                if(s.count(x)){
                    queue<TreeNode*> qq;
                    qq.emplace(node->left);
                    while(!qq.empty()){
                        TreeNode* node = qq.front();
                        qq.pop();
                        if(s.count(node->val)){
                            s.erase(node->val);
                            if(node->left) qq.emplace(node->left);
                            if(node->right) qq.emplace(node->right);
                        }
                        else{
                            q.emplace(node);
                            res.emplace_back(node);
                        }
                    }
                    node->left = nullptr;
                }
                else{
                    q.emplace(node->left);
                }
            }
            if(node->right){
                x = node->right->val;
                if(s.count(x)){
                    queue<TreeNode*> qq;
                    qq.emplace(node->right);
                    while(!qq.empty()){
                        TreeNode* node = qq.front();
                        qq.pop();
                        if(s.count(node->val)){
                            s.erase(node->val);
                            if(node->left) qq.emplace(node->left);
                            if(node->right) qq.emplace(node->right);
                        }
                        else{
                            q.emplace(node);
                            res.emplace_back(node);
                        }
                    }
                    node->right = nullptr;
                }
                else{
                    q.emplace(node->right);
                }
            }
        }
        return res;*/
        vector<TreeNode*> res;
    }
    //[1,2,null,4,3]\n[2,3]
};
// @lc code=end

