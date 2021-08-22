/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        //solution1:使用deque，23%/11%
        /*vector<int> nums;
        vector<int> opers;
        for(int i = 0;i < s.size();++i){
            if(s[i] == ' ') continue;
            else if(s[i]=='+') opers.emplace_back(1);
            else if(s[i]=='-') opers.emplace_back(2);
            else if(s[i] == '/') opers.emplace_back(4);
            else if(s[i] == '*') opers.emplace_back(3);
            else{
                int j = i;
                while(j < s.size()&&s[j]<='9'&&s[j]>='0') ++j;
                int num = stoi(s.substr(i,j-i));
                i = j-1;
                //cout<<num<<endl;
                if(!opers.empty()&&(opers.back()==3||opers.back()==4)){
                    int pre = nums.back();
                    nums.pop_back();
                    int oper = opers.back();
                    opers.pop_back();
                    switch(oper){
                        case 3:num = pre*num;break;
                        case 4:num = pre/num;
                    }
                }
                nums.emplace_back(num);
            }
        }
        int res = nums[0],j = 1;
        for(int i = 0;i < opers.size();++i){
            switch(opers[i]){
                case 1:res += nums[j];break;
                case 2:res -= nums[j];
            }
            ++j;
        }
        return res;*/
        //solution2:参考答案--利用这是基本计算器，直接存为+1，-2最后accumulate即可，不用存oper的stack
        //50%18%
        vector<int> nums;
        char oper;
        for(int i = 0;i < s.size();++i){
            if(s[i] == ' ') continue;
            if(s[i]>'9'||s[i]<'0') oper = s[i]; 
            else{
                int j = i;
                while(j < s.size()&&s[j]<='9'&&s[j]>='0') ++j;
                int num = stoi(s.substr(i,j-i));
                i = j-1;
                if(oper=='/'||oper=='*'){
                    int pre = nums.back();
                    nums.pop_back();
                    switch(oper){
                        case '*':num = pre*num;break;
                        case '/':num = pre/num;
                    }
                }
                else if(oper == '-') num = -num;
                nums.emplace_back(num);
            }
        }
        int res =0;
        res = accumulate(nums.begin(),nums.end(),res);
        return res;
    }
    //"42"
    //"1-1+1"
    //"0-2147483647"
};
// @lc code=end

