/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //参考答案提示:快慢指针
        //note:考虑清除第一个的情况，加入dummy方便很多!
        // 其实应该增加一些delete dummy和left->next,但是会增加时间复杂度
        if(!head) return head;
        ListNode* dummy= new ListNode(0,head);
        ListNode *left = dummy,*right = head;
        while(right&&n--) right = right->next;
        while(right){
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
    //[1,2,3,4,5]\n2
    //[1,2]\n1
    //[1,2]\n2
    //[1]\n1
    //[1,2,3]\n1
};
// @lc code=end

