/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    // 三指针：solution3-遍历一个i，将jk转化为二指针问题！O(nlogn) + O(n^2)
    // solution0: O(n^3)
    // solution1: O(n*n*logn) 固定两头遍历中间
    //  策略：双指针，固定住一头-从i遍历，j相对i改变且要遍历，二分查找k
    //  pnt1: 思考清楚必须要遍历i+遍历j+二分k O(n*n*logn)
    //  pnt2: 重复元素问题思考清楚-可以有重复元素，但是不能有重复元组
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int> > res;
        // sort(nums.begin(), nums.end());
        // int i = 0, j = nums.size()-1;
        // for (;i < j - 1; ++i) {
        //     // cout<<i<<" "<<j<<endl;
        //     // -4,-1,-1,0,1,2
        //     if (i > 0 && nums[i] == nums[i-1] || nums[i] + nums[j] * 2 < 0) continue;
        //     if (nums[i] == 0 && i + 2 < nums.size() && nums[i+2] == 0) {
        //         res.emplace_back(vector<int> {0,0,0});
        //     }
        //     if (nums[i] >= 0) break;
        //     while (i < j - 1 && 2 * nums[i] + nums[j] > 0) --j;
        //     if (i >= j - 1) break;
        //     for (int tmp_j = j; i < tmp_j - 1 && nums[i] + 2 * nums[tmp_j] >= 0; --tmp_j) {
        //         if (tmp_j +1 < nums.size() && nums[tmp_j] == nums[tmp_j + 1]) continue;
        //         int tmp = -nums[i]-nums[tmp_j];
        //         int tmp_idx = lower_bound(nums.begin()+i+1, nums.begin() + tmp_j, tmp) - nums.begin();
        //         if (tmp_idx != tmp_j && nums[tmp_idx] == tmp) {
        //             res.emplace_back(vector<int> {nums[i],tmp,nums[tmp_j]});
        //         }
        //     }
        //     // [1,2,-2,-1]
        // }
        // return res;
    // solution3-参考答案顺序遍历first->second->third O(n^2)
    // 遍历first然后转化为二指针问题second+third两侧确定，寻找
        vector<vector<int> > res;
        if(nums.size() < 3) return res;
        sort(nums.begin(),nums.end());
        int first ,second, third;
        for (first = 0; first < nums.size()-2; ++first) {
            if (first > 0 && nums[first - 1] == nums[first]) continue;
            third = nums.size()-1;
            if (nums[first] + nums[third-1] + nums[third] < 0) continue;
            for (second = first + 1; second < third; ++second) {
                if (second > first + 1 && nums[second-1] == nums[second]) continue;
                while (second < third && nums[first] + nums[second] + nums[third] > 0) --third;
                if (second<third && nums[first] + nums[second] + nums[third] == 0) res.emplace_back(vector<int> {nums[first],nums[second],nums[third]});
            }
        }
        return res;
    }
};
// @lc code=end

