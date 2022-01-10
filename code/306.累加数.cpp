/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
public:
    bool helpAdditiveNumber(string& num, long long num1, long long num2, int pos) {
        string sum_s = to_string(num1 + num2);
        if (pos + sum_s.size() > num.size() || num.substr(pos,sum_s.size())!=sum_s) {
            return false;
        }
        // cout<< num1<<" "<<num2<<" "<<sum_s<<endl;
        if (pos + sum_s.size() == num.size()) return true;
        return helpAdditiveNumber(num, num2, num1+num2,pos+sum_s.size());
    }
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        long long num1 = 0, num2 = 0;
        for (int i = 0; i + 2 < num.size() ; ++i) {
            num1 = num1 * 10 + (num[i]-'0');
            if (num1 >= 1e18) break;
            num2 = 0;
            for (int j = i + 1; j + 1 < num.size(); ++j) {
                num2 = num2 * 10 + (num[j]-'0');
                if (num2 >= 1e18) break;
                if (helpAdditiveNumber(num, num1, num2, j+1)) return true;
                if (j == i+1 && num[j] == '0') break;
            }
            if (i == 0 && num[i] == '0') break;
        }
        return false;
    }
    // tip1:"000"特殊值0
    // tip2:long long处理

};
// @lc code=end

