/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        queue<Node*> q;
        unordered_map<int,Node*> hash;
        q.emplace(node);
        while(!q.empty()){
            Node* cur_node = q.front();
            q.pop();
            if(!hash.count(cur_node->val)){
                Node* new_node = new Node(cur_node->val);
                hash[cur_node->val] = new_node;
            }
            else continue;
            for(Node* next:cur_node->neighbors){
                if(!hash.count(next->val)){
                    q.emplace(next);
                }
                else{
                    (hash[next->val]->neighbors).emplace_back(hash[cur_node->val]);
                    (hash[cur_node->val]->neighbors).emplace_back(hash[next->val]);
                }
            }
        }
        return hash[node->val];
    }
};
// @lc code=end

