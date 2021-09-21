/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
    class TrieNode{
    public:
        TrieNode* child[26];
        bool isWord;
        TrieNode():isWord(false) {
            for(int i = 0;i < 26;++i) child[i] = nullptr;
        }
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* node = root;
        for(const char&ch:word){
            if(!(node->child[ch-'a'])) node->child[ch-'a'] = new TrieNode();
            node = node->child[ch-'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return searchfromNode(root,word,0);
    }
    bool searchfromNode(TrieNode* node,string& word,int pos) {
        if(pos == word.size()-1) {
            if(word[pos] == '.') {
                for(int i = 0;i < 26;++i) {
                    if(node->child[i]&&node->child[i]->isWord) return true;
                }
                return false;
            }
            if(node->child[word[pos]-'a']&&node->child[word[pos]-'a']->isWord) return true;
            return false;
        }
        if(word[pos]=='.'){
            for(int i = 0;i < 26;++i){
                if(!(node->child[i])) continue;
                if(searchfromNode(node->child[i],word,pos+1)) return true;
            }
            return false;
        } 
        if(!(node->child[word[pos]-'a'])) return false;
        node = node->child[word[pos]-'a'];
        return searchfromNode(node,word,pos+1);
    }
    //["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]\n[[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

