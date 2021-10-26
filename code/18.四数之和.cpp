/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    //本题极大混乱：事先想好结构（怎样循环+重复数值怎么保存）再写比查缺补漏强多了了
    //参考答案：双指针+剪枝.固定一头，另一头遍历！;
    //分析-由于这种有数值关系限制，因此可以两边制约进行双指针，不用无脑dp！!这种问题不能用dp，有很多重复性计算！！！！
    //tip1:note！明确right含义，搜索边界而不是固定边界
    //tip2:剪枝细节，及时break
    //tip3:判断时用/而不用*,容易越界!!
    //solution2-优化:其实受答案按时走了弯路，不用两边，单边使用4个指针暴力往后遍历也可：想好剪枝和停止条件
    //p1：条件为num[p1] > targe/4.0 ->break;注意这里4.0 否则-15/-3 不停
    //每次取值考虑全重复值即可,这里使用unordered_map记录步长
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() <= 3) return res;
        unordered_map<int,int> hash;
        for(const int& n:nums){
            if(hash.count(n)) ++hash[n];
            else hash[n] = 1;
        }
        sort(nums.begin(),nums.end());
        int p1 = 0;
        for(int p1 = 0;p1 + 3 < nums.size();p1 += hash[nums[p1]]){
            if(nums[p1] > target/4.0) break;
            if(4 * nums[p1] == target){
                if(hash[nums[p1]] >= 4) res.emplace_back(vector<int> {nums[p1],nums[p1],nums[p1],nums[p1]});
                break;//这划分参考了答案，先判等，不符合也可以break
            }
            if(hash[nums[p1]] >= 3){
                int tmp = target - 3 * nums[p1];
                if(hash.count(tmp)) {
                    res.emplace_back(vector<int> {nums[p1],nums[p1],nums[p1],tmp});
                }
            }
            if(hash[nums[p1]] >= 2){
                int tmp = target -  2*nums[p1];
                for(int p3 = p1 + hash[nums[p1]];p3 + 1< nums.size(); p3 += hash[nums[p3]]){
                    if(tmp < 2*nums[p3]) break;
                    else{
                        if(tmp != 2*nums[p3]&&hash.count(tmp-nums[p3])||tmp == 2*nums[p3]&&hash[nums[p3]] >= 2) {
                            res.emplace_back(vector<int> {nums[p1],nums[p1],nums[p3],tmp - nums[p3]});
                        }
                    }
                }
            }
            for(int p2 = p1 + hash[nums[p1]];p2 + 2 < nums.size();p2 += hash[nums[p2]]){
                int tmp = target - nums[p1];
                if(nums[p2] > tmp/3) break;
                else if(3*nums[p2] == tmp){
                    if(hash[nums[p2]] >= 3) {
                        res.emplace_back(vector<int> {nums[p1],nums[p2],nums[p2],nums[p2]});
                    }
                    break;
                }
                if(hash[nums[p2]] >= 2){
                    tmp -= 2*nums[p2];
                    if(tmp > nums[p2]&&hash.count(tmp)) {
                        res.emplace_back(vector<int> {nums[p1],nums[p2],nums[p2],tmp});
                    }
                }
                tmp = target - nums[p1] - nums[p2];
                for(int p3 = p2 + hash[nums[p2]];p3 + 1 < nums.size();p3 += hash[nums[p3]]){
                    if(tmp < 2*nums[p3]) break;
                    else if(tmp == 2 * nums[p3]){
                        if(hash[nums[p3]] >= 2) {
                            res.emplace_back(vector<int> {nums[p1],nums[p2],nums[p3],nums[p3]});
                        }
                        break;
                    }
                    if(hash.count(tmp - nums[p3])) {
                        res.emplace_back(vector<int> {nums[p1],nums[p2],nums[p3],tmp - nums[p3]});
                    }
                }
            }
        }
        return res;
        //[-9,-6,-3,-5,-10,-6,1,-7,7,-1,-3,-10,5,-3,-8,-8,4,0,-7]\n-15
    }
};
// @lc code=end

