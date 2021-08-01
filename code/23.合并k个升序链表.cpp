/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    //way1:手写priority_queue
    /*vector<ListNode*> heap;
    //tip3!!：注意这里heap左子树2*i+1，右子树2*i+2（针对0开头）;左子树2*i，右子树2*i+1（针对1开头）
    void push(ListNode* node){
        if(node == nullptr) return;
        heap.push_back(node);
        swim(heap.size() - 1);
    }
    ListNode* top(){
        ListNode* res = heap[0];
        heap[0] = heap[0]->next;
        if(heap[0]==nullptr){
            heap[0] = heap.back();
            heap.pop_back();
        }
        sink(0);
        return res;
    }
    void swim(int i){
        //tip1:注意临界值，相等值
        //tip2:审题，分方向，大顶堆/小顶堆
        while(i >= 1 && heap[i]->val < heap[(i-1)/2]->val){
            swap(heap[i],heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    void sink(int i){
        while(2 * i + 1< heap.size()){
            int j = 2 * i + 1;
            if(j < heap.size() - 1 && heap[j]->val > heap[j+1]->val) ++j;
            if(heap[j]->val >= heap[i]->val) break;
            else {
                swap(heap[i],heap[j]);
                i = j;
            }
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0;i < lists.size();i++) push(lists[i]);
        ListNode *head = nullptr,*last = nullptr,*newNode = nullptr;
        while(heap.size()){
            newNode = top();
            if(last != nullptr){
                last->next = newNode;
            }
            else{
                head = newNode;
            }
            last = newNode;
        }
        return head;
    }*/
    //way2:直接用priority_queue
    //这种有k个定值得排序，适合priority_queue
    //tip1:！！！priority_queue排序可以在struct里重载<符号；或者写成单独一个cmp
    struct cmp{
        bool operator ()(ListNode* p1,ListNode* p2){
		    return p1->val > p2->val;//现在是最小的在前，注意与sort的cmp方向相反
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp > q;
        for(ListNode* p:lists){
            if(p) q.push(p);
        }
        ListNode* head = nullptr,*last = nullptr,*cur = nullptr;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(!head){
                head = cur;
                last = head;
            }
            else{
                last->next = cur;
            }
            last = cur;
            if(cur->next) q.push(cur->next);
        }
        return head;
    }
};
// @lc code=end

