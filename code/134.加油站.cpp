/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        //note:return index (minIndex+1)%gas.size()
        gas[0] = gas[0] - cost[0];
        int minIndex = 0;
        int len = gas.size();
        for(int i = 1;i < len;i++){
            gas[i] = gas[i-1] + gas[i]-cost[i];
            if(gas[i] < gas[minIndex]) minIndex = i;
        }
        if(gas[len- 1] < 0) return -1;
        return (minIndex+1)%len;
    }
};
// @lc code=end

