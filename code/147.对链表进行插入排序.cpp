/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* pre = head;
        while(pre->next){
            ListNode* node = pre->next;
            if(node->val >= pre->val) pre = node;
            else{
                pre->next = node->next;
                ListNode* new_pre = dummy;
                while(new_pre->next->val <= node->val) new_pre = new_pre ->next;
                node->next = new_pre->next;
                new_pre->next = node;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

