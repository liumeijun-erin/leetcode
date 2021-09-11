/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* pre,*left_p,*tmp,*dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        right = right-left;
        while(--left) pre = pre ->next;
        left_p = pre->next;
        while(right--){
            tmp = left_p->next;
            left_p->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy->next;
        //链表题考虑head
        //[3,5]\n1\n2
        //[1,2,3,4,5]\n2\n4
    }
};
// @lc code=end

