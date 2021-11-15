/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
public:
    string add(string& s1, string& s2) {
        int pre = 0;
        int pos1 = s1.size() - 1, pos2 = s2.size() - 1;
        string res = "";
        while (pos1 >= 0 && pos2 >= 0) {
            int tmp = pre + (s1[pos1--] - '0') + (s2[pos2--] - '0');
            res += (tmp%10) + '0';
            pre = tmp/10;
        }
        while (pos1 >= 0) {
            int tmp = pre + (s1[pos1--] - '0');
            res += (tmp%10) + '0';
            pre = tmp/10;
        }
        while (pos2 >= 0) {
            int tmp = pre + (s2[pos2--] - '0');
            res += (tmp%10) + '0';
            pre = tmp/10;
        }
        if (pre) res += (pre + '0');
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool help(string& num, string& pre1_s, string& pre2_s, int pos) {
        while (pos < num.size()) {
            string tmp = add(pre1_s,pre2_s);
            for(int i = 0;i < tmp.size();++i) {
                if(pos >= num.size() || num[pos++] != tmp[i]) return false;
            }
            swap(pre1_s,pre2_s);
            swap(pre2_s,tmp);
        }
        return true;
    }

    bool isAdditiveNumber(string num) {
        for (int end1 = 1; end1 < num.size(); ++end1) {
            if (num[end1] == '0' &&num[0]!='0'&& end1 + 1 < num.size() && num[end1+1] == '0') {
                continue;
            }
            for (int end2 = end1 + 1; end2 < num.size(); ++end2) {
                if (num[end2] == '0' &&num[end1] == '0'&& end2 + 1 < num.size() && num[end2 + 1] == '0') {
                    continue;
                }
                string pre1_s = num.substr(0,end1);
                string pre2_s = num.substr(end1,end2-end1);
                if (help(num,pre1_s,pre2_s,end2)) return true;
            }
        }
        return false;
    }
    //"101" 
    //"000"

};
// @lc code=end

