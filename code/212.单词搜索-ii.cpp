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
    class TrieNode{
        public:
        TrieNode* child[26];
        bool isWord;
        TrieNode():isWord(false){
            for(int i = 0;i < 26;++i){
                child[i] = nullptr;
            }
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie():root(new TrieNode()){}
        void insert(string word){
            TrieNode* temp = root;
            for(int i = 0;i < word.size();++i){
                if(!temp->child[word[i]-'a']){
                    temp->child[word[i]-'a'] = new TrieNode();
                }
                temp = temp->child[word[i]-'a'];
            }
            temp->isWord = true;
        }
    };
    vector<int> d{-1,0,1,0,-1};
    void dfs(vector<string>& res,Trie& wordTree,vector<vector<char>>& board,int x,int y,string& cur_str,TrieNode*& cur_node){
        if(cur_node->isWord) {
            res.emplace_back(cur_str);
            cur_node->isWord = false;
        }
        for(int i = 0;i < 4;++i){
            if(x+d[i]<0||x+d[i]>=board.size()||y+d[i+1]<0||y+d[i+1]>=board[0].size()) continue;
            char ch = board[x+d[i]][y+d[i+1]];
            if(ch == '\0') continue;
            if(cur_node->child[ch-'a']) {
                TrieNode* tmp = cur_node;
                cur_node = cur_node->child[ch-'a'];
                cur_str += ch;
                board[x+d[i]][y+d[i+1]] = '\0';
                dfs(res,wordTree,board,x+d[i],y+d[i+1],cur_str,cur_node);
                board[x+d[i]][y+d[i+1]] = ch;
                cur_node = tmp;
                cur_str.pop_back();
            }
        }
    }
    public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie wordTree;
        for(const string& s:words){
            wordTree.insert(s);
        }
        vector<string> res;
        string tmp = "";
        TrieNode* node = wordTree.root;
        int m = board.size(),n = board[0].size();
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                char ch = board[i][j];
                node = wordTree.root->child[ch-'a'];
                if(node) {
                    tmp += ch;
                    board[i][j] = '\0';
                    dfs(res,wordTree,board,i,j,tmp,node);
                    board[i][j] = ch;
                    tmp = "";
                }
            }  
        }
        return res;
        //bug1:只有hklf没有hf：由于cur_node传值没有改回去
        //[["o","d","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain","hklf", "hf"]
    }
};
// @lc code=end

