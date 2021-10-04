/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //考虑+-：0
        //转换成正数后考虑-2147483648
        // 1\n-2147483648
        if(numerator == 0) return "0";
        bool isNeg = false;
        long long numerator_ll = numerator;
        long long denominator_ll = denominator;
        if(numerator < 0){
            numerator_ll = -numerator_ll;
            if(denominator < 0) denominator_ll = -denominator_ll;
            else isNeg = true;
        }
        else if(denominator < 0){
            denominator_ll = -denominator_ll;
            isNeg = true;
        }
        string res = to_string(numerator_ll / denominator_ll);
        numerator_ll = numerator_ll % denominator_ll;
        if(numerator_ll) {
            res += '.';
            unordered_map<int,int> hash;
            while(numerator_ll){
                if(hash.count(numerator_ll)){
                    res += ')';
                    res.insert(res.begin()+hash[numerator_ll],'(');
                    break;
                }
                else{
                    hash[numerator_ll] = res.size();
                }
                numerator_ll *= 10;
                res += (numerator_ll / denominator_ll)+'0';
                numerator_ll = numerator_ll % denominator_ll;
            }
        }
        if(isNeg) res.insert(res.begin(),'-');
        return res;
    }
};
// @lc code=end

