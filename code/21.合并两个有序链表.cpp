/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*n1 = l1,*n2 = l2,*dummy = new ListNode(0),*head = dummy;
        while(n1&&n2){
            if(n2->val < n1->val){
                dummy->next = n2;
                dummy = n2;
                n2 = n2->next;
            }
            else{
                dummy->next = n1;
                dummy = n1;
                n1 = n1->next;
            }
        }
        if(n1) dummy->next = n1;
        else dummy->next = n2;
        return head->next;
    }
};
// @lc code=end

