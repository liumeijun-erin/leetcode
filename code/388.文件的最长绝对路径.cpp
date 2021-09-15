/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        //note:'\n'是一个字符，不能拆成\和n
        vector<int> level;
        int cur_level,cur;
        int res = 0;
        int i = 0;
        while(i < input.size()){
            cur_level = 0;
            while(i < input.size()&&input[i]=='\n'||input[i]=='\t'){
                ++cur_level;
                ++i;
            }
            if(cur_level){
                --cur_level;
            }
            if(cur_level) cur = level[cur_level-1]+1;
            else cur = 0;
            bool isfile = false;
            while(i<input.size()&&input[i]!='\n'){
                if(input[i]=='.') isfile =true;
                ++cur;
                ++i;
            }
            if(isfile) res = max(res,cur);
            if(level.size()>=cur_level+1) level[cur_level] = cur;
            else level.emplace_back(cur);
        }
        return res;
        //"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
    }
};
// @lc code=end

