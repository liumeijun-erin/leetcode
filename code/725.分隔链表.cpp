/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0,i;
        vector<ListNode*> res;
        ListNode* node = head;
        while(node){
            node = node->next;
            ++cnt;
        }
        for(i = 0;i < k;++i){
            res.emplace_back(head);
            node = head;
            int len = cnt/k;
            if(i < cnt%k) ++len;
            while(--len&&node) node = node->next;
            if(node){
                head = node->next;
                node->next = nullptr;
            }
        }
        return res;
    }
};
// @lc code=end

