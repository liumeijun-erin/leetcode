/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // 有想到用next存储节省空间，但没想好怎么实现
    // 参考官方答案：利用next指针构建层次结构！使用last+next_layer_start+layer_start帮助构建！
    // 先想一个基础的baseline：queue实现bfs，then优化空间，不是利用bfs建立next；
    // 而是去掉bfs利用上层next关系就可以实现下层next关系
    Node* connect(Node* root) {
        Node* node = root;
        Node* lower = nullptr;
        Node* head = nullptr;
        while (node) {
            if (node->left) {
                if (!head) head = node->left;
                if (lower) lower->next = node->left;
                    lower = node->left;
            }
            if (node->right) {
                if (!head) head = node->right;
                if (lower) lower->next = node->right;
                lower = node->right;
            }
            if (!(node->next)) {
                lower = nullptr;
                node = head;
                head = nullptr;
            }
            else node = node->next;
        }
        return root;
    }
};
// @lc code=end

