/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //审题："1.2"\n"1.10"返回-1！！！注意这里是十的意思不是1+0！！！
        //注意一定要考虑数值多位的情况,边界！
        //"1.0.1"\n"1"
        //"1.2"\n"1.10"
        //"7.5.2.4"\n"7.5.3"
        //"1"\n"0"
        //像这样查缺补漏式写法写的细而乱,虽然结果挺快但是写的过程慢
        //应该下笔之前想好思路：边界：./endl，状态:compare==0时再向后比较
        //note：注意两种边界重合的时候一个.一个endl要注意判断当前compare！
        int i = 0,j = 0,compare;
        while(i < version1.length()&&j < version2.length()){
            compare = 0;
            while(i < version1.length()&&version1[i]=='0') ++i;
            while(j < version2.length()&&version2[j]=='0') ++j;
            if(i == version1.length()||j == version2.length()) break;
            while(i < version1.length()&&j < version2.length()){
                if(version1[i]=='.'&&version2[j]=='.') {
                    ++i;++j;
                    break;
                }
                else if(version1[i] == '.') return -1;
                else if(version2[j] == '.') return 1;
                else if(!compare){
                    if(version1[i] < version2[j]) compare = -1;
                    else if(version1[i] > version2[j]) compare = 1;
                }
                ++i;
                ++j;
            }
            if(i < version1.length()&&j == version2.length()){
                if(version1[i] == '.') {
                    if(compare) return compare;
                    ++i;
                    break;
                }
                else return 1;
            }
            if(j < version2.length()&&i == version1.length()){
                if(version2[j] == '.') {
                    if(compare) return compare;
                    ++j;
                    break;
                }
                else return -1;
                
            }
            if(compare) return compare;
        }
        if(i == version1.length()&&j == version2.length()) return compare;
        if(i < version1.length()){
            while(i < version1.length()){
                if(version1[i]!='0'&&version1[i]!='.') return 1;
                ++i;
            }
        }
        else{
            while(j < version2.length()){
                if(version2[j]!='0'&&version2[j]!='.') return -1;
                ++j;
            }
        }
        return 0;
    }
};
// @lc code=end

