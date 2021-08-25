/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *pre = head,*cur = head->next;
        while(cur){
            if(cur->val == pre->val){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        return head;
    }
};
// @lc code=end

