/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        //tip1: hash-table,use the alphabetic order as array index(key),frequency as value
        //vector<int> count(26);
        int count[26] = {0}; //faster
        int n = s.length();//faster
        int i;
        for(i = 0;i < n;i++){
            count[s[i] - 'a'] += 1;
        }
        for(i = 0;i < n;i++){
            if(count[s[i] - 'a'] == 1){
                break;
            }
        }
        if(i == s.length()) return -1;
        else return i;
    }
    //tip2: unordered_map,use the letter as key,string index as value
    //tip3: use unordered_map & queue(fifo)
};
// @lc code=end

