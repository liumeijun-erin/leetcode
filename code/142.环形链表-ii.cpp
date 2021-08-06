/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast!=NULL) {
            if(fast->next) fast = fast->next->next;
            else fast = fast->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        //需要画图查看
        if(fast != NULL){
            fast = head;
            while(slow != fast){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return fast;
    }
};
// @lc code=end

