/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class TrieNode{
    //参考答案，先设计TrieNode数据结构！！！
    public:
        TrieNode* childNode[26];
        bool isWord;//标记是否是单词结尾
        TrieNode():isWord(false){
            for(int i = 0;i < 26;++i){
                childNode[i] = nullptr;
            }
        }
};
class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(const char& ch:word){
            if(!((node->childNode)[ch-'a'])){
                (node->childNode)[ch-'a'] = new TrieNode();
            }
            node = (node->childNode)[ch-'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(const char& ch:word){
            if(!((node->childNode)[ch-'a'])) return false;
            node = (node->childNode)[ch-'a'];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(const char& ch:prefix){
            if(!((node->childNode)[ch-'a'])) return false;
            node = (node->childNode)[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

