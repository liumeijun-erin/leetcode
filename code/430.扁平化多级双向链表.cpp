/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* dummy = new Node,*pre = dummy;
        stack<Node*> s;
        s.emplace(head);
        while(!s.empty()){
            Node* node = s.top();
            s.pop();
            pre ->next = node;
            node->prev = pre;
            while(node){
                while(node&&!(node->child)) {
                    pre = node;
                    node = node->next;
                }
                if(!node) break;
                if(node->next) s.emplace(node->next);
                node->next = node->child;
                node->child->prev = node;
                node->child = nullptr;
                pre = node;
                node = node->next;
            }
        }
        head->prev = nullptr;
        delete dummy;
        return head;
    }
};
// @lc code=end

