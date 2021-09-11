/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int n) {
        //TODO:clever 转化！
        //solution2:参考答案：！！！讲相邻不能11抽象为二叉树的01选择
        //利用前缀树！！小于等于n的0、1前缀树确保11不相邻然后输出所有叶子！
        //solution1:bp把数字拆成各位,针对各位数字bp
        //思路1：二进制数的位数n res[n] = res[n-2]+num[n-1]
        //题目中使用累加
        //区分110001可以直接处理/100001递归处理
        /*if(n <= 2) return n+1;
        if(n == 3) return 3;
        vector<int> bit;
        vector<int> res = {0,1};
        int ans = n+1,tmp=0;
        while(n){
            bit.emplace_back(n%2);
            n /= 2;
        }
        int len = bit.size();
        int num = 2,i;
        for(i = 2;i < len-1;++i){
            res.emplace_back(res[res.size()-2]+res[res.size()-1]+num);
            num *= 2;
        }
        num *= 2;
        i = len - 1;
        int cnt = ans-1;
        while(i>0){
            //cout<<i<<endl;
            tmp += res[i-1];
            cnt -= num;
            if(bit[i-1]){
                num/=2;
                if(i==1) tmp += 1;
                else{
                    cnt -= num;
                    tmp += (cnt+1);
                }
                if(i >= 2) tmp += res[i-2];
                break;
            }
            --i;
            num/=2;
            while(i>0&&!bit[i]) {
                --i;
                num /= 2;
            }
        }
        return ans-tmp;*/
        //solution2:参考答案：！！！讲相邻不能11抽象为二叉树的01选择
        //利用前缀树！！小于等于n的0、1前缀树确保11不相邻然后输出所有叶子！
        //8:1000
        //19:10011
        //87:1010110
        //7:111
        //31:11111
    }
};
// @lc code=end

