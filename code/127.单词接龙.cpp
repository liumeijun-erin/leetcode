/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    bool diff(string& w1, string& w2) {
        int cnt = 0;
        for (int i = 0;i < w1.size(); ++i) {
            if (w1[i] != w2[i]) {
                if (cnt) return false;
                else cnt = 1;
            }
        }
        return (cnt == 1);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<int> > next(wordList.size());
        vector<bool> visited(wordList.size(),false);
        queue<int> q;
        int begin_id = -1, end_id = -1;
        for (int i = 0;i < wordList.size(); ++i) {
            if (beginWord == wordList[i]) begin_id = i;
            else if(endWord == wordList[i]) end_id = i;
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (diff(wordList[i], wordList[j])) {
                    next[i].emplace_back(j);
                    next[j].emplace_back(i);
                }
            }
        }
        int step = 0;
        if (begin_id == -1) {
            for (int i = 0;i < wordList.size(); ++i) {
                if (diff(wordList[i], beginWord)) {
                    if (i == end_id) return 2;
                    q.emplace(i);
                    visited[i] = true;
                }
            }
            ++step;
        }
        else {
            q.emplace(begin_id);
            visited[begin_id] = true;
        }
        while(!q.empty()){
            ++step;
            int len = q.size();
            while (len--) {
                int cur_word = q.front();
                q.pop();
                for (const int& next_word:next[cur_word]) {
                    if (visited[next_word]) continue;
                    visited[next_word] = true;
                    if (next_word == end_id) return step+1;
                    q.emplace(next_word);
                }
            }
        }
        return 0;
    }
};
// @lc code=end

