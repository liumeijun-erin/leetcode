/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
    //线段树模板!
    //solution:参考答案线段树！每个节点包含[i-j]的信息，左节点[i-mid],右节点[mid-right]
    //暴力解可能9*10^8超时
    int n;
    int *tree = nullptr;
public:
    NumArray(vector<int>& nums){
        n = nums.size();
        tree = new int[2*n];
        for(int i = n;i < 2*n;++i){
            tree[i] = nums[i-n];
        }
        for(int i = n-1;i > 0;--i){
            tree[i] = tree[2*i]+tree[2*i+1];
        }
    }
    void update(int index, int val) {
        int d = val - tree[n+index];
        int cur = n + index;
        while(cur>0){
            tree[cur] += d;
            cur /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        left += n;
        right += n;
        while(left <= right){
            if(left %2){
                sum += tree[left];
                ++left;
            }
            if(right%2==0){
                sum += tree[right];
                --right;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

