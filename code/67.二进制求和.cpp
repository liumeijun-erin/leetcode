/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1,j = b.size() - 1,k = 0;
        while(i >= 0 || j >= 0){
            k += (i >= 0 && a[i] == '1');
            k += (j >= 0 && b[j] == '1');
            if(k%2) res = "1"+res;
            else  res = "0" + res;
            k /= 2;
            --i;
            --j;
            //cout<<i<<" "<<j<<endl;
        }
        if(k) res = "1" + res;
        return res;
    }
};
// @lc code=end

