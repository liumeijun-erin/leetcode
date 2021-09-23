/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1,*pre;
        int t = 0;
        while(l1!=nullptr&&l2!=nullptr){
            int tmp = (l1->val+l2->val+t)/10;
            l1->val = (l1->val+l2->val+t)%10;
            t =tmp;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2!=nullptr){
            pre->next =l2;
            l1 = pre->next;
        }
        if(t){
            while(l1&&t) {
                int tmp = (l1->val+t)/10;
                l1->val= (l1->val+t)%10;
                t = tmp;
                pre = l1;
                l1 = l1->next;
            }
            if(t) {
                pre->next= new ListNode(t);
            }
        }
        return head;
    }
};
// @lc code=end

