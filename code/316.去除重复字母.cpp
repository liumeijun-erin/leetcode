/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> hash;
        for(const char&c:s){
            if(!hash.count(c)) hash[c] = 1;
            else ++hash[c];
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        string res = "";
        int pre = -1;
        for(int i = 0;i < s.size();++i){
            if(!hash.count(s[i])) continue;
            if(hash[s[i]] == 1){
                cout<<s[i]<<endl;
                while(!pq.empty()){
                    char c = pq.top().first+'a';
                    int pos = pq.top().second;
                    if(c > s[i]) break;
                    cout<<c<<" "<<pos<<endl;
                    pq.pop();
                    if(!hash.count(c)||pos<=pre) continue;
                    res += c;
                    hash.erase(c);
                    pre = pos;
                }
                if(hash.count(s[i])){
                    res += s[i];
                    hash.erase(s[i]);
                    pre = i;
                }
            }
            else{
                pq.emplace(make_pair(s[i]-'a',i));
                --hash[s[i]];
            }
        }
        return res;
        //"cbaacabcaaccaacababa"
    }
};
// @lc code=end

