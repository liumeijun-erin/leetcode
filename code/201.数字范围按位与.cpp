/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    //思路：找公共前缀
    //solution1：转换成string，慢
    /*string toBinary(int a){
        string s;
        while(a){
            if(a%2) s = "1"+ s;
            else s = "0"+s;
            a = a/2;
        }
        return s;
    }*/
    int rangeBitwiseAnd(int left, int right) {
        /*int num = 0;
        string s1=  toBinary(left),s2 = toBinary(right);
        //cout<<s1<<" "<<s2<<endl;
        int i = 0,j = 0;
        if(s1.size()!=s2.size()) return 0;
        while(i < s1.size()){
            if(s1[i]==s2[j]){
                if(s1[i] == '1') num = num*2 + 1;
                else num = num*2;
            }
            else break;
            ++i;
            ++j;
        }
        while(i++<s1.size()) num = num*2;
        return num;*/
        //solution2：tip1：参考答案，判断长度不等过于exhausting，所以不单独判断，而是和其它情况一起写，在过程中筛出来
        //tip2：高位遍历得到ans困难，可以转化为m+shift位移个数
        int shift = 0;
        while(left!=right){
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left<<shift;
    }
};
// @lc code=end

