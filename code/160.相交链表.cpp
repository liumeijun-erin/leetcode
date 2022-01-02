/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //solution1:使用unordered_set
        /*if(!headA||!headB) return nullptr;
        ListNode* node = headA;
        unordered_set<ListNode*> s;
        int len = 0,lenA;
        while(node){
            ++len;
            s.insert(node);
            node = node ->next;
        }
        lenA = len;
        node = headB; 
        while(node){
            ++len;
            s.insert(node);
            node = node ->next;
        }
        len -= s.size();
        if(len <= 0) return nullptr;
        len = lenA - len;
        node = headA;
        while(len--){
            node = node->next;
        }
        return node;
    }*/

        // solution2：参考答案，快慢指针
        // 思路：
        // 有重复：a + b + c == b + c + a
        // 无重复：a + b == b + a, return nullptr
        ListNode *l1 = headA, *l2 = headB;
        while (l1 != l2) {  // 允许l1 l2为nullptr作为判断条件
            l1 = l1? l1->next: headB;
            l2 = l2? l2->next: headA;
        }
        return l1;

        // solution3：利用遍历得到len1，len2关系
        // ListNode *pA = headA;
        // ListNode *pB = headB;
        // int lenA = 0, lenB = 0;
        // while (pA) {
        //     pA = pA->next;
        //     ++lenA;
        // }
        // while (pB) {
        //     pB = pB->next;
        //     ++lenB;
        // }
        // pA = headA;
        // pB = headB;
        // while (lenA > lenB) {
        //     pA = pA->next;
        //     ++lenB;
        // }
        // while (lenA < lenB) {
        //     pB = pB->next;
        //     ++lenA;
        // }
        // while(pA && pA!=pB) {
        //     pA = pA ->next;
        //     pB = pB ->next;
        // }
        // if (pA && pA == pB) return pA;
        // return nullptr;
    }
};
// @lc code=end

