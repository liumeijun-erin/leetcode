/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int dep = 0;
        if(!root) return dep;
        queue<Node*> q;
        q.emplace(root);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                Node* tmp_n = q.front();
                for (Node* c: tmp_n->children) {
                    q.emplace(c);
                }
                q.pop();
            }
            ++dep;
        }
        return dep;
    }
};
// @lc code=end

