/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        if(root) {
            queue<TreeNode*> q;
            q.emplace(root);
            while(!q.empty()){
                if(q.front() == nullptr){
                    res += "null,";
                }
                else{
                    int v = q.front()->val;
                    res += to_string(v) + ',';
                    q.emplace(q.front()->left);
                    q.emplace(q.front()->right);
                }
                q.pop();
            }
            res.pop_back();
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() <= 2) return nullptr;
        data[data.size()-1] = ',';
        int pos = 1,next = data.find(',',pos);
        TreeNode* root = new TreeNode(atoi(data.substr(pos,next-pos).c_str()));
        pos = next + 1;
        queue<TreeNode*> q;
        q.emplace(root);
        while(pos < data.size() - 1){
            next = data.find(',',pos);
            string tmp = data.substr(pos,next-pos);
            if(tmp != "null"){
                TreeNode* leftNode = new TreeNode(atoi(tmp.c_str()));
                q.front()->left = leftNode;
                q.emplace(leftNode);
            }
            pos = next + 1;
            next = data.find(',',pos);
            tmp = data.substr(pos,next-pos);
            if(tmp != "null"){
                TreeNode* rightNode = new TreeNode(atoi(tmp.c_str()));
                q.front()->right = rightNode;
                q.emplace(rightNode);
            }
            q.pop();
            pos = next + 1;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

