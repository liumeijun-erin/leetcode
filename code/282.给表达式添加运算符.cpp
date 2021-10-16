/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
public:
    //  本题过是过了，但是很复杂；参考答案可以从宏观dfs处遍历当前符号以及截取的位数
    //答案巧妙！只针对特殊的乘号运算+遍历位数
    //tip1:！！！遍历取的位数这种方法
    //tip2:！！！只针对变出现乘号的情况巧妙处理：对于连乘，采取保存中间最后一次计算结果--随时撤销,并更新计算即可
    //https://leetcode-cn.com/problems/expression-add-operators/solution/gei-biao-da-shi-tian-jia-yun-suan-fu-by-2o1s7/
    //  solution1:按位遍历，要保存的中间变量很多。时间复杂度复杂
    /*void help(vector<string>& res,string ans,string& num,int pos,int& target,long long sum,int pre_oper,long long pre_num,int cur_oper,long long cur_num){
        if(pos == num.size()){
            if(cur_oper == 3) {
                if(pre_oper) pre_num *= cur_num;
                else sum *= cur_num;
            }
            if(pre_oper == 1) sum += pre_num;
            else if(pre_oper == 2) sum -= pre_num;
            if(cur_oper == 1) sum += cur_num;
            else if(cur_oper == 2) sum -= cur_num;
            if(sum == target) res.emplace_back(ans);
            return;
        }
        //无操作
        if(cur_num) help(res,ans+num[pos],num,pos+1,target,sum,pre_oper,pre_num,cur_oper,cur_num*10 + (num[pos]-'0'));
        //有操作
        if(cur_oper==3){
            if(pre_oper) pre_num *= cur_num;
            else sum *= cur_num;
        }
        else {
            if(pre_oper){
                if(pre_oper == 1) sum += pre_num;
                else sum -= pre_num;
            }
            pre_oper = cur_oper;
            pre_num = cur_num;
        }
        //*
        ans += '*';
        ans += num[pos];
        help(res,ans,num,pos+1,target,sum,pre_oper,pre_num,3,num[pos]-'0');
        ans[ans.size()-2] = '+';
        help(res,ans,num,pos+1,target,sum,pre_oper,pre_num,1,num[pos]-'0');
        ans[ans.size()-2] = '-';
        help(res,ans,num,pos+1,target,sum,pre_oper,pre_num,2,num[pos]-'0');
    }
    vector<string> addOperators(string num, int target) {
        //审题，有可能什么也不加
        vector<string> res;
        string ans = "";
        ans += num[0];
        help(res,ans,num,1,target,0,0,0,1,num[0]-'0');
        return res;
    }*/
    //"123456789"\n45
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        vector<string> ans;

        function<void(string&, int, long, long)> backtrack = [&](string &expr, int i, long res, long mul) {
            if (i == n) {
                if (res == target) {
                    ans.emplace_back(expr);
                }
                return;
            }
            int signIndex = expr.size();
            if (i > 0) {
                expr.push_back(0); // 占位，下面填充符号
            }
            long val = 0;
            // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
            for (int j = i; j < n && (j == i || num[i] != '0'); ++j) {
                val = val * 10 + num[j] - '0';
                expr.push_back(num[j]);
                if (i == 0) { // 表达式开头不能添加符号
                    backtrack(expr, j + 1, val, val);
                } else { // 枚举符号
                    expr[signIndex] = '+'; backtrack(expr, j + 1, res + val, val);
                    expr[signIndex] = '-'; backtrack(expr, j + 1, res - val, -val);
                    expr[signIndex] = '*'; backtrack(expr, j + 1, res - mul + mul * val, mul * val);
                }
            }
            expr.resize(signIndex);
        };

        string expr;
        backtrack(expr, 0, 0, 0);
        return ans;
    }
};
// @lc code=end

