/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
public:
    string help(int num,string& res){
        if(num >= 1000000000){
            help(num/1000000000,res);
            res += " Billion";
            help(num%1000000000,res);
        }
        else if(num >= 1000000){
            help(num/1000000,res);
            res += " Million";
            help(num%1000000,res);
        }
        else if(num >= 1000){
            help(num/1000,res);
            res += " Thousand";
            help(num%1000,res);
        }
        else if(num >= 100){
            help(num/100,res);
            res += " Hundred";
            help(num%100,res);
        }
        else{
            if(num >= 10){
                if(res != "") res += " ";
                if(num/10 == 9) res += "Ninety";
                else if(num/10 == 8) res += "Eighty";
                else if(num/10 == 7) res += "Seventy";
                else if(num/10 == 6) res += "Sixty";
                else if(num/10 == 5) res += "Fifty";
                else if(num/10 == 4) res += "Forty";
                else if(num/10 == 3) res += "Thirty";
                else if(num/10 == 2) res += "Twenty";
                else {
                    if(num == 10) res += "Ten";
                    else if(num == 11) res += "Eleven";
                    else if(num == 12) res += "Twelve";
                    else if(num == 13) res += "Thirteen";
                    else if(num == 14) res += "Fourteen";
                    else if(num == 15) res += "Fifteen";
                    else if(num == 16) res += "Sixteen";
                    else if(num == 17) res += "Seventeen";
                    else if(num == 18) res += "Eighteen";
                    else if(num == 19) res += "Nineteen";
                    return res ;
                }
                num %= 10;
            }
            if(num){
                if(res != "") res += " ";
                if(num == 9) res += "Nine";
                else if(num == 8) res += "Eight";
                else if(num == 7) res += "Seven";
                else if(num == 6) res += "Six";
                else if(num == 5) res += "Five";
                else if(num == 4) res += "Four";
                else if(num == 3) res += "Three";
                else if(num == 2) res += "Two";
                else res += "One";
            }
        }
        return res;
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        string res = "";
        help(num,res);
        return res;
    }
};
// @lc code=end

