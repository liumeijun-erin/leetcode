/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
//  前缀树加记忆化搜索:！！！分析问题重复性！！！
//  前缀树tip1：
//  * 前缀树实现可以把Trie部分写在solution里
//  * 参考答案做了一些小改进：传引用+pos，而不是substr
// 
//  记忆化搜索：明确重复性在于前面oooooxxxxx, xxxxx无解
//  但会多次遍历到xxxxx位置，所以要在isConnectedWord里补充每一位的visited
//  记录该位到结尾的字符串是否经过判断
// 
// 参考答案tip:a里超时:["a","aa","aaa","aaaa","aaaaa","...
// 改进重点在于：isConnected则不往里insert了
//这里节约一大步

class TrieNode{
public:
    bool isWord;
    TrieNode* childNode[26];
    TrieNode():isWord(false){
        for (int i = 0; i < 26; ++i) {
            childNode[i] = nullptr;
        }
    }
};
class Solution {
    TrieNode* root;
public:
    void insert(const string& word) {
        TrieNode* node = root;
        for (const char& c: word) {
            if (!(node->childNode[c-'a'])) node->childNode[c-'a'] = new TrieNode();
            node = node->childNode[c-'a'];
        }
        node->isWord = true;
    }
    bool isConnectedWord(const string& word, int pos, vector<int>& ms) {
        if (pos == word.size()) return true;
        if (ms[pos] == 1) return true;
        else if(ms[pos] == -1) return false;
        // cout<<word<<" "<<pos<<endl;
        TrieNode* node = root;
        int tmp_pos = pos;
        for (int i = pos; i < word.size(); ++i) {
            int idx = word[i]-'a';
            if (!(node->childNode[idx])) return false;
            node = node->childNode[idx];
            if (node->isWord && isConnectedWord(word,i+1,ms)) {
                ms[pos] = 1;
                return true;
            }
        }
        ms[pos]= -1;
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        root = new TrieNode();
        sort(words.begin(), words.end(), [](string& s1, string& s2){
            return s1.size() < s2.size();
        });
        for (const string& word: words) {
            if (word == "") continue;
            vector<int> ms(word.size());
            if (isConnectedWord(word,0,ms)) res.emplace_back(word);
            else insert(word);
            //参考答案改进--这里else非常重要！
        }
        return res;
    }
};
// @lc code=end

