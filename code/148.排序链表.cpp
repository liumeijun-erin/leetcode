/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    //   参考答案：展开自底而上；这样可以避免迭代增加的空间负担
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        ListNode* tmp1 = head1;
        ListNode* tmp2 = head2;
        while (tmp1 != nullptr && tmp2 != nullptr) {
            if (tmp1->val <= tmp2->val) {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            }
            else {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }
        if (tmp1 != nullptr) {
            tmp->next = tmp1;
        }
        else if(tmp2 != nullptr) {
            tmp->next = tmp2;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = 0;
        ListNode* node = head;
        while (node != nullptr) {
            ++len;
            node = node->next;
        }
        ListNode* dummy = new ListNode(0, head);
        for (int sublen = 1; sublen < len; sublen <<= 1) {
            ListNode* prev = dummy;
            ListNode* curr = dummy ->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < sublen && curr->next != nullptr; ++i) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                ListNode* next = nullptr;
                curr = head2;
                if (curr != nullptr) {
                    for (int i = 1; i < sublen && curr->next != nullptr; ++i) {
                        curr = curr->next;
                    }
                    next = curr->next;
                    curr->next = nullptr;
                } 
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummy->next;
    }
    //tricky：
    //tip1：注意边界next处理！！！
    //tip2:注意传指针参数,不能原地改变
    //todo:可以改进成不用左闭右闭区间，而是用nullptr标记
    // 要考虑递归的空间利用O(logn)
    // ListNode* mergeSort(ListNode* n1,ListNode* n2){
    //     if(n1 == n2) return n1;
    //     //tip3:使用快慢指针找中点
    //     ListNode* left = n1,*right = n1;
    //     while(right&&right->next&&right->next->next) {
    //         //note!!!注意这里的边界条件！
    //         //[4,2,1,3]
    //         left = left->next;
    //         right = right->next->next;
    //     }
    //     ListNode* mid = left->next;
    //     left->next = nullptr;
    //     //边界
    //     ListNode* p1 = mergeSort(n1,left);
    //     ListNode* p2 = mergeSort(mid,n2);
    //     ListNode* tmp = new ListNode(0),*node,*cur = tmp;
    //     while(p1&&p2){
    //         if(p1->val<p2->val) {
    //             node = p1;
    //             p1 = p1->next;
    //         }
    //         else {
    //             node = p2;
    //             p2 = p2->next;
    //         }
    //         node->next = cur->next;
    //         cur->next = node;
    //         cur = node;
    //     }
    //     if(p1) {
    //         cur->next = p1;
    //     }
    //     else if(p2){
    //         cur->next = p2;
    //     }
    //     return tmp->next;
    // }
    // ListNode* sortList(ListNode* head) {
    //     if(!head||!(head->next)) return head;
    //     ListNode* node = head;
    //     while(node->next) node=node->next;
    //     return mergeSort(head,node);
    //     //todo:可以改进成不用左闭右闭区间，而是用nullptr标记
    // }
    //[4,2,1,3]
};
// @lc code=end   

