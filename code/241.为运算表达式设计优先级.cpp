/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        //way1:divide and conquer
        /*vector<int> res;
        bool isNum = true;
        for(int i = 0;i < expression.length();++i){
            char ch = expression[i];
            if(ch == '+'||ch == '*'||ch =='-'){
                isNum = false;
                vector<int> x = diffWaysToCompute(expression.substr(0,i));
                vector<int> y = diffWaysToCompute(expression.substr(i+1,expression.length() - i - 1));
                for(const int & xx:x){
                    for(const int & yy:y){
                        switch(ch){
                            case '+':
                                res.push_back(xx+yy);
                                break;
                            case '-':
                                res.push_back(xx-yy);
                                break;
                            case '*':
                                res.push_back(xx*yy);
                        }
                    }
                }
            }
        }
        if(isNum){
            //cout<<stoi(expression)<<endl;
            res.push_back(stoi(expression));
        }
        return res;
        */
        //way2:dynamic programming
        vector<int> data;
        vector<char> oper;
        int num;
        char op;
        //tip1:istringstream方法:可以分割空格隔离的字符；还可以按照格式读取！
        istringstream ss(expression + "+");
        while (ss >> num && ss >> op) {
            data.push_back(num);
            oper.push_back(op);
        }
        int n = data.size();
        //tip2:多维vector数组长度格式可以这样说明
        vector<vector<vector<int> > > dp(n,vector<vector<int> > (n,vector<int>()));
        for(int i = 0;i < n;++i){
            dp[i][i].push_back(data[i]);
        }
        for(int i = 1;i < n;++i){
            for(int j = 0;j < n - i;++j){
                for(int k = j; k < j + i;k++){
                    for(auto left:dp[j][k]){
                        for(auto right:dp[k+1][j+i]){
                            switch(oper[k]){
                                case '+':dp[j][j+i].push_back(left + right);break;
                                case '-':dp[j][j+i].push_back(left - right);break;
                                case '*':dp[j][j+i].push_back(left * right);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

