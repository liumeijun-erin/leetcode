/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //参考答案：可以从中点构造，不用一个一个insert和调整
        if(!head) return nullptr;
        ListNode* slow = head,*fast= head->next;
        if(!(head->next)) fast = slow;
        else{
             while(fast&&fast->next&&fast->next->next){
                //note:快慢指针找list中点时候要注意边界条件！
                fast = fast->next->next;
                slow = slow->next;
            }
            fast = slow->next;
        }
        slow->next = nullptr;
        TreeNode* root = new TreeNode(fast->val);
        //cout<<fast->val<<endl;
        if(fast!=head) root->left = sortedListToBST(head);
        fast = fast->next;
        root->right = sortedListToBST(fast);
        return root;
    }
    // TreeNode* help(ListNode* head, int len) {
    //     if (len == 0) return nullptr;
    //     ListNode* node = head;
    //     int len_left = len/2;
    //     while(len_left--) node = node->next;
    //     TreeNode* root = new TreeNode(node->val);
    //     root->left = help(head, len/2);
    //     root->right = help(node->next, len-len/2-1);
    //     return root;
        
    // }
    // TreeNode* sortedListToBST(ListNode* head) {
    //     ListNode* node = head;
    //     int len = 0;
    //     while (node) {
    //         node = node->next;
    //         ++len;
    //     }
    //     return help(head,len);
    // }
};
// @lc code=end

