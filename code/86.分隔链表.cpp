/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0,head),*node = dummy, *pre = dummy;
        while(pre->next&&pre->next->val<x){
            pre = pre->next;
        }
        node = pre -> next;
        while(node){
            while(node->next&&node->next->val>=x) node = node->next;
            if(!node->next) break;
            ListNode* tmp = node->next;
            node->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = tmp;
            //cout<<node->val<<" "<<pre->val<<endl;
            

        }
        return dummy->next;
    }
};
// @lc code=end

