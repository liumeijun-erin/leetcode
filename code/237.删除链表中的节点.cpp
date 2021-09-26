/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
    //  审题得只有node没有其他，参考了答案swap!!!
    //链表结构无法改变的时候改变值
    void deleteNode(ListNode* node) {
        ListNode *pre = node;
        while(pre->next){
            pre->val = pre->next->val;
            if(!pre->next->next) break;
            pre = pre->next;
        }
        ListNode* tmp = pre->next;
        pre->next = nullptr;
        delete tmp;
    }
};
// @lc code=end

