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
        if (!root) return root;
        Node* layer_start = root;
        while (layer_start) {
            Node* last = nullptr;
            Node* next_layer_start = nullptr;//这个设置参考了答案layer_start + next_layer_start
            for (Node* n = layer_start; n != nullptr; n = n->next) {
                if (n->left) {
                    if (last) last->next = n->left;
                    else next_layer_start = n->left;
                    last = n->left;
                }
                if (n->right) {
                    if (last) last->next = n->right;
                    else next_layer_start = n->right;
                    last = n->right;
                }
            }
            layer_start = next_layer_start;
        }

        return root;
        // [1,2,3,4,5,null,6,7,null,null,null,null,8]
    }
};
// @lc code=end

