/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* reverseList(ListNode* head,ListNode* end){
        ListNode* dummy = new ListNode(0,nullptr);
        ListNode* p;
        while(head){
            //note：！！！head!=end->next不可以！！
            p = head;
            head = head->next;
            p->next = dummy->next;
            dummy->next = p;
        }
        return dummy->next;
    }
    bool isPalindrome(ListNode* head) { 
        //参考答案，可以使用快慢指针找到中间和结尾
        int n = 0;
        ListNode* n1 = head,*n2 = head;
        if(n1->next==nullptr) return true;
        while(n1->next&&n1->next->next){
            n1 = n1 ->next;
            n1 = n1 ->next;
            n2 = n2 ->next;
        }
        if(n1->next){
            n1 = n1->next;  
        }
        ListNode* p1 = head,*p2 = reverseList(n2->next,n1);
        while(p1&&p2){
            if(p1->val != p2 ->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
    //[1,2,2,1]
    //[1]
    //[1,2]
    //[0,0]
    //[1,1,2,1]
};
// @lc code=end

