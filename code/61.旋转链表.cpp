/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* fast = head ,*slow = head;
        ListNode* dummy =new ListNode();
        dummy->next = head;
        do{
            fast = head;
            int cnt = 1;
            int tmp_k = k;
            while(fast->next&&k){
                fast = fast->next;
                ++cnt;
                --k;
            }
            if(tmp_k%cnt==0) return head;
            if(k) {
                k = tmp_k%cnt;
            }
        }while(k);
        if(fast == slow) return head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next= dummy->next;
        dummy->next = slow->next;
        slow->next = nullptr;
        return dummy->next;
    }
    // [0,1,2]\n4
};
// @lc code=end

