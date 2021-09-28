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
        if(!head) return head;
        Node* dummy = new Node(0),*a_node = head,*pre = dummy,*b_node;
        unordered_map<Node*,Node*> hash;
        while(a_node){
            b_node = new Node(a_node->val);
            hash[a_node] = b_node;
            pre ->next = b_node;
            pre = b_node;
            a_node = a_node->next;
        }
        b_node = dummy->next;
        a_node = head;
        while(b_node){
            if(a_node->random == nullptr) b_node->random = nullptr;
            else b_node->random = hash[a_node->random];
            a_node = a_node->next;
            b_node = b_node->next;
        }
        return dummy->next;
        //[[3,null],[3,0],[3,null]]
    }
};
// @lc code=end

