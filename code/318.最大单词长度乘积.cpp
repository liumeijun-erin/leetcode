/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> p(26,1);
        for(int i = 1;i < 26;++i) p[i] = p[i-1] << 1;
        vector<int> record(words.size(),0);
        int maxn = 0;
        for(int i = 0;i < words.size();++i){
            string word = words[i];
            for(const char& ch:word){
                if(!(record[i]&p[ch-'a'])){
                    //注意&的优先级比较低，所以要加括号
                    record[i] |= p[ch-'a'];//可以用+，也可以用|
                    //答案也可以不用p数组，1 << (ch-'a')现算即可
                } 
            }
            for(int j = 0;j < i;++j){
                if(!(record[i]&record[j])){
                    //注意&的优先级比较低，所以要加括号
                    //cout<<record[i]<<" "<<record[j]<<endl;
                    int len = word.size() * words[j].size();
                    maxn = max(maxn,len);
                }
            }
        }
        return maxn;
        
    }
};
// @lc code=end

 