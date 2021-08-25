/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!(head->next)) return head;
        ListNode* node = head->next,*end = head;
        while(node&&node->next){
            ListNode* tmp = node->next;
            node->next = tmp->next;
            tmp->next = end->next;
            end->next = tmp;
            node = node->next;
            end = tmp;
        }
        return head;
    }
};
// @lc code=end

