/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *fast= head,*slow = head,*tmp;
        while(fast->next&&fast->next->next){
            slow = slow -> next;
            fast = fast -> next ->next;
        }
        ListNode* dummy = new ListNode();
        while(slow->next){
            tmp = slow->next;
            slow->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        fast = head,slow = dummy->next;
        while(fast&&slow){
            tmp = slow;
            slow = slow->next;
            tmp->next = fast->next;
            fast->next = tmp;
            fast = fast->next->next;
        }
    }
};
// @lc code=end

