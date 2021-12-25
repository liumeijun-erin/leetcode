/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node*, Node*> hash;
        Node* tmp = head;
        Node* tmp_new;
        while (tmp) {
            Node* tmp_new = new Node(tmp->val);
            hash[tmp] = tmp_new;
            tmp = tmp->next;
        }
        tmp_new = hash[head];
        tmp = head;
        while (tmp_new) {
            tmp_new->next = hash[tmp->next];
            if(tmp->random) tmp_new->random = hash[tmp->random];
            tmp_new = tmp_new->next;
            tmp = tmp->next;
        }
        return hash[head];
    }
};
// @lc code=end

