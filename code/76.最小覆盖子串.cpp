/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        /*
        //solution1:重点在于考虑aaaab\nab情况，可用，超60%
        unordered_map<char,int> hash;
        unordered_map<char,int> cnt;
        for(const char& c:t){
            ++hash[c];
        }
        int i = 0;
        while(i<s.length()&&!hash.count(s[i])) ++i;
        if(i >= s.length()) return "";
        int j = i;
        bool containAll;
        while(j < s.length()){
            if(hash.count(s[j])){
                ++cnt[s[j]];
                containAll = true;
                for(auto &p:hash){
                    if(cnt[p.first] < p.second) containAll = false;
                }
                ++j;
                if(containAll) break;
            }
            else ++j;
        } 
        if(!containAll) return "";
        //!考虑好初始情况是否能完全正确，第一个不一定保留！eg "bba"\n"ba" "aa"\n"a"
        while(cnt[s[i]] > hash[s[i]]){
            --cnt[s[i++]];
            while(!hash.count(s[i])) ++i;
        }
        int start = i,end = j-1;
        //cout<<start<<" "<<end<<endl;
        while(j < s.length()){
            if(!hash.count(s[j])) {
                ++j;
                continue;
            }
            ++cnt[s[j]];
            if(s[j] == s[i]){
                while(i < j){
                    //cout<<i<<" "<<j<<" "<<cnt[s[i]]<<" "<<hash.count(s[i])<<endl;
                    if(!hash.count(s[i])){
                        ++i;
                    }
                    else if(cnt[s[i]] > hash[s[i]]){
                        --cnt[s[i]];
                        ++i;
                    }
                    else break;
                }
                if(j-i<end - start){
                    start = i;
                    end = j;
                }
            }
            ++j;
        }
        return s.substr(start,end - start + 1);*/
        //solution2:记录关键项位置队列，加快更新，争取O(n);
        //优化次数存储，通过正负数一个map即可
        //个人感觉应该是有优化，但是结果显示不明显。超过72%
        queue<int> q;
        unordered_map<char,int> cnt;
        for(const char& c:t){
            --cnt[c];
        }
        //note:针对aaab,解决办法-利用queue将i设置为b前数目刚好的a的位置;在计算start/end的时候处理
        int i = 0,j = s.length()-1;
        bool containsAll,first=true;
        for(int k = 0;k < s.length();++k){
            if(!cnt.count(s[k]))  continue;
            ++cnt[s[k]];
            q.emplace(k);
            if(first){
                containsAll = true;
                for(auto& p:cnt){
                    if(p.second < 0) containsAll = false;
                }
                if(containsAll){
                    first = false;
                }
                else{
                    continue;
                }
            }
            while(!q.empty()&&cnt[s[q.front()]]>0){
                --cnt[s[q.front()]];
                q.pop();
            }
            if(k- q.front()< j -i){
                i = q.front();
                j = k;   
            }
        }
        if(!containsAll) return "";
        //审题，考虑特殊情况
        return s.substr(i,j-i+1);
    }
};
// @lc code=end

