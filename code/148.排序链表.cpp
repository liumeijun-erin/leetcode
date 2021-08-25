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
    //tricky：
    //tip1：注意边界next处理！！！
    //tip2:注意传指针参数,不能原地改变
    //todo:可以改进成不用左闭右闭区间，而是用nullptr标记
    ListNode* mergeSort(ListNode* n1,ListNode* n2){
        if(n1 == n2) return n1;
        //tip3:使用快慢指针找中点
        ListNode* left = n1,*right = n1;
        while(right&&right->next&&right->next->next) {
            //note!!!注意这里的边界条件！
            //[4,2,1,3]
            left = left->next;
            right = right->next->next;
        }
        ListNode* mid = left->next;
        left->next = nullptr;
        //边界
        ListNode* p1 = mergeSort(n1,left);
        ListNode* p2 = mergeSort(mid,n2);
        ListNode* tmp = new ListNode(0),*node,*cur = tmp;
        while(p1&&p2){
            if(p1->val<p2->val) {
                node = p1;
                p1 = p1->next;
            }
            else {
                node = p2;
                p2 = p2->next;
            }
            node->next = cur->next;
            cur->next = node;
            cur = node;
        }
        if(p1) {
            cur->next = p1;
        }
        else if(p2){
            cur->next = p2;
        }
        return tmp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!(head->next)) return head;
        ListNode* node = head;
        while(node->next) node=node->next;
        return mergeSort(head,node);
        //todo:可以改进成不用左闭右闭区间，而是用nullptr标记
    }
    //[4,2,1,3]
};
// @lc code=end   

