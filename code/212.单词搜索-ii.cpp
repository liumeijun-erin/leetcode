/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
    //tip1:使用trie加快单词查找
    //tip2：事先想好传引用/传值，visited/board类传指针其他改+恢复/传值均可。记得处理好
    //experiment1:node和tmp传值20.65%/81.76% 传指针28.68%、78.49%
    // root作为私有变量非常重要！否则超时
    class Solution {
    class TrieNode {
    public:
        bool is_word;
        TrieNode* next[26];
    };
    TrieNode* root;
    vector<int> d = {-1,0,1,0,-1};
public:
    void insert_word(const string& word) {
        TrieNode* node = root;
        for (const char& c: word) {
            if (node->next[c-'a'] == nullptr) {
                node->next[c-'a'] = new TrieNode();
            }
            node = node->next[c-'a'];
        }
        node->is_word = true;
    }

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode*& node, vector<string>& res, string& tmp){
        char c = board[x][y];
        board[x][y] = '0';
        tmp += c;
        if (node->is_word) {
            res.emplace_back(tmp);
            // cout<<tmp<<endl;
            node->is_word = false;
        }
        for (int i = 0; i < 4; ++i) {
            int new_x = x + d[i], new_y = y + d[i+1];
            if (new_x >= board.size() || new_x < 0 || new_y >= board[0].size() || new_y < 0) continue;
            if (board[new_x][new_y] == '0') continue;
            TrieNode* tmp_node = node->next[board[new_x][new_y]-'a'];
            if (tmp_node != nullptr) {
                TrieNode* swap_node = node;
                node = tmp_node;
                dfs(board, new_x, new_y, node, res, tmp);
                node = swap_node;
            }
        }
        tmp.pop_back();
        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (string& word: words) insert_word(word);

        vector<string> res;
        int m = board.size(), n = board[0].size();
        string tmp = "";
        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                TrieNode* node =  root->next[board[x][y]-'a'];
                if(node) dfs(board, x, y, node, res, tmp);
            }
        }

        return res;
        //bug1:只有hklf没有hf：由于cur_node传值没有改回去
        //[["o","d","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain","hklf", "hf"]
    }
};
// @lc code=end

