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
        if (!head||!head->next) return head;
        ListNode* fast = head;
        int len = 0;
        for (int i = 0;i < k; ++i) {
            fast = fast->next;
            ++len;
            if(!fast) break;
        }
        if (!fast) {
            k = k % len;
            fast = head;
            while(k--) fast = fast->next;
        }
        if (k == 0) return head;
        ListNode* slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
    // [0,1,2]\n4
};
// @lc code=end

