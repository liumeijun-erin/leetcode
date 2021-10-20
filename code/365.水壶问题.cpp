/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
public:
    //本题不会：需要思考，精简思路
    //参考答案思路：！！！捋清思路-每次把不满的水倒掉，无意义，相当于满水倒掉，每次把不满水加满也无意义，相当于空杯加水
    //因此每次加水倒水都是对x y处理：求ax+by = z
    //裴蜀定理可知使ax+by = z有解当且仅当 z 是 x, yx,y 的最大公约数的倍数！！！！
    /*solution1:超时
    //注意这里要有标记visited(准确的说是已经入栈的内容)
    bool help(int& jug1, int& jug2, int& t,int h1,int h2,vector<vector<bool> >& dp){
        if(h1 + h2 == t) return true;
        if(dp[h1][h2]) return false;
        dp[h1][h2] = true;
        //精简:参考答案思路：每次把不满的水倒掉，无意义，相当于满水倒掉，每次把不满水加满也无意义，相当于空杯加水
        //因此每次加水倒水都是对x y处理
        bool res = false;
        if(h1 != jug1) res = res || help(jug1,jug2,t,h1,jug2,dp);
        else res = res || help(jug1,jug2,t,0,h2,dp);
        if(h2 != jug2) res = res || help(jug1,jug2,t,jug1,h2,dp);
        else res = res || help(jug1,jug2,t,h1,0,dp);
        if(h2 + h1 >= jug1) res = res || help(jug1,jug2,t,jug1,h2 + h1 -jug1,dp);
        else res = res || help(jug1,jug2,t,h1 + h2,0,dp);
        if(h2 + h1 >= jug2) res = res || help(jug1,jug2,t,h1 + h2 -jug2,jug2,dp);
        else res = res || help(jug1,jug2,t,0,h1 + h2,dp);
        return res;
    }
    bool canMeasureWater(int jug1, int jug2, int t) {
        if(t > jug1+jug2||t < 0) return false;
        if(t == 0||jug1 == t||jug2 == t||jug1 + jug2 == t) return true;
        vector<vector<bool> > dp(jug1+1,vector<bool> (jug2+1,0));
        //也可以用set,而不是unordered-无法直接用pair
        return help(jug1,jug2,t,0,0,dp);
    }*/
    bool canMeasureWater(int jug1, int jug2, int t) {
        if(t > jug1+jug2||t < 0) return false;
        if(t == 0||jug1 == t||jug2 == t||jug1 + jug2 == t) return true;
        return t % gcd(jug1, jug2) == 0;
        //试问是否有ax+by = z且过程中不能超过x+y：贝祖定理可知使ax+by = z有解当且仅当 z 是 x, yx,y 的最大公约数的倍数！！！！
    }

};
// @lc code=end

