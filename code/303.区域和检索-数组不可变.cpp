/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    //tip:答案中利用partial_sum自动生成a，a+b，a+b+c...
    vector<int> sum;
    NumArray(vector<int> nums): psum(nums.size() + 1, 0) {
        partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
    }
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int cnt = 0;
        for(const int& num:nums){
            cnt += num;
            sum.emplace_back(cnt);
        }
    }
    
    int sumRange(int left, int right) {
        if(!left) return sum[right];
        else return sum[right] - sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

