/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //用手画出结果数组总结规律
        //参考答案：使用双向列表+其实类似于单调栈:利用数组变形存储中间信息！！！使用一个新数组保存从当前k开始的
        //way1:超时
        /*for(int i = 1;i < nums.size();++i){
            for(int j = i - 1;j >= 0&&j > i - k;--j) nums[j] = max(nums[i],nums[j]);
        }
        for(int i = 0;i < k - 1;++i) nums.pop_back();
        return nums;*/
        //！！！！合理安排数据结构，保存所需要的所有局部信息，动态更新比较即可！！！
        //way2：答案much faster，不存在一个数组，而是存一个值，实时生成答案！！！
        //保存所需要的所有局部信息即可，不需要随时更新
        //随着变化实时生成答案!!，且pop_front操作deque明显快很多
        /*deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            //因为只需要靠近i的值，所以小于当前的都可以删掉；保存索引可以判断距离！
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }   
            dq.push_back(i);    
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;*/
        //way3:自己反省重写一遍m,其实可以原地覆盖，对于每个nums[i]与前k个比较,大的话覆盖，小的话接在后面
        //但是由于k可能很大，所以使用deque进行优化,由于deque首位为当前可取最大的，所以小的留着直到一旦有大的可能解都清空
        //答案中deque中存的是index
        if(k == 1) return nums;
        vector<int> res;
        deque<int> q;
        for(int i = 0;i < nums.size();i++){
            while(!q.empty()&&q.back() < nums[i]) q.pop_back();
            q.emplace_back(nums[i]);
            if(i >= k - 1) {
                res.emplace_back(q.front());
                if(nums[i - k + 1] == q.front()) q.pop_front();
            }
        }
        return res;
    }
};
// @lc code=end

