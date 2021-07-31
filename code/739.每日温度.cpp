/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    //使用stack已经隐含了栈顶一定是小，一定是有序栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> ss;
        vector<int> res(temperatures.size());
        ss.push(0);
        for(int i = 1;i < temperatures.size();i++){
            while(!ss.empty()&&temperatures[i] > temperatures[ss.top()]){
                //temperatures[ss.top()] = i - ss.top();
                res[ss.top()] = i - ss.top();
                ss.pop();
            }
            ss.push(i);
        }
        /*while(!ss.empty()){
            temperatures[ss.top()] = 0;
            ss.pop();
        }
        return temperatures;*/
        return res;
    }
};
// @lc code=end

