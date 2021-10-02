/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    //单调栈+ 哨兵(单哨兵)
    //此题型属于经典不会系列！单调栈+哨兵数组！保存局部信息(栈中保存当前最小和当前最大，动态弹栈压栈的过程中记录了每个驻点的左右）！！！
    //参考答案
    //step1:将问题转换为某一个高度height和两侧均大于等于他的width！
    //step2：利用单调栈——通过控制栈中递增，可以得到隐含信息：两侧均大于他的位置！保存到哨兵left，right数组里
    //隐含利用利用了每次局部高值一定在里面！！！！反证法可得
    //单调栈update方法：当出现小于栈顶的的再开始一个一个pop_back，保证栈顶最小
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        //vector<int> right(n,-1);优化，只存一个哨兵
        stack<int> s;
        int res = 0;
        for(int i = 0;i <n ;++i){
            //勿忘相邻两点==情况
            left[i] = i;
            while(!s.empty()&&heights[i] <= heights[s.top()]){
                //right[s.top()] = i-1;
                left[i] = left[s.top()];//important
                //left[i] = s.top();//不能解决==[999,999]
                //res = max(res,heights[s.top()]*(right[s.top()]-left[s.top()]+1));
                res = max(res,heights[s.top()]*(i-1-left[s.top()]+1));
                s.pop();
            }
            s.emplace(i);
        }
        while(!s.empty()){
            res = max(res,heights[s.top()]*(n-left[s.top()]));
            s.pop();
        }
        return res;
        //[1,1]
        //[2,3]
    }
};
// @lc code=end

