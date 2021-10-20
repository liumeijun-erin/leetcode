/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<int> n = {1000,500,100,50,10,5,1};
        vector<char> c = {'M','D','C','L','X','V','I'};
        string res = "";
        for(int i = 0;i <= 6;++i){
            int cnt = num/n[i];
            num = num%n[i];
            while(cnt--) res += c[i];
            if(i == 6) break;
            ++i;
            if(num >= 9*n[i+1]) {
                res += c[i+1];
                res += c[i-1];
                num %= n[i+1];
            }
            else{
                cnt = num/n[i];
                num = num%n[i];
                if(num >= 0.8*n[i]){
                    res += c[i+1];
                    res += c[i];
                    num -= 0.8*n[i];
                }
                if(cnt) res += c[i];
            }
            
        }
        return res;
    }
};
// @lc code=end

