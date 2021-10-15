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
        ListNode* dummy = new ListNode(0,head),*node = dummy,*pre = dummy;
        while(node->next&&node->next->val<x){
            node = node->next;
        }
        pre = node->next;
        cout<<node->val<<endl;
        if(!pre) return head;
        while(pre->next){
            while(pre->next&&pre->next->val>=x) pre = pre->next;
            if(pre->next){
                ListNode* tmp = pre->next;
                tmp->next = node->next;
                node->next = tmp;
                node = tmp;
                //cout<<node->val<<" "<<pre->val<<endl;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

