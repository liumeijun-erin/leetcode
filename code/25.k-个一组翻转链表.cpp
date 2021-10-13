/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverse(int k,ListNode* slow,ListNode* fast){
        //cout<<slow->next->val<<" "<<fast->val<<endl;
        ListNode* pre = slow->next,*tmp = nullptr;
        while(--k){
            //tmp = slow->next;
            tmp = pre->next;
            pre->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k == 1) return head;
        ListNode* dummy =new ListNode();
        dummy->next = head;
        ListNode* slow = dummy,*fast = slow,*next;
        int tmp_k = k;
        while(fast->next){
            tmp_k = k;
            fast = slow;
            while(fast->next&&tmp_k--){
                fast = fast->next;
            }
            if(tmp_k&&fast->next==nullptr) break;
            slow = reverse(k,slow,fast);
        }
        return dummy->next;
    }
};
// @lc code=end

