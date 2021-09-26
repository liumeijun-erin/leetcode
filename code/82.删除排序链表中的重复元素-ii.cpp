/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        ListNode* dummy = new ListNode(0,head),* cur = dummy;
        while(cur ->next&&cur->next->next){
            //delete内存了，但是表现不好
            /*int tmp_val = cur->next->val;
            if(cur->next->next->val == tmp_val){
                while(cur->next&&cur->next->val==tmp_val){
                    ListNode* tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                }
            }*/
            //这样没有delete表现稍微好一点
             if(cur->next->next->val == cur->next->val){
                ListNode* tmp = cur->next->next;
                while(tmp&&tmp->val==cur->next->val){
                    tmp = tmp->next;
                }
                cur->next = tmp;
            }
            else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

