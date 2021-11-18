/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution {
public:
    //  !!!nth-element，3-way-partition=逆序穿插，虚地址！！！
    //   本题参考答案：nth-element+ 3-way-partition可以避免排序! 逆序插入避免中位数相遇！虚地址节省空间复杂度！
    //   整体思路：分为小段和大段两两配对
    //   key pnt1: 参考答案:找中位数可以使用快排O(n) + 3-way-partition确保中位数集中起来+ 逆序穿插解决中位数相遇问题
    //   参考答案:快排可以使用nth-element 
    //   auto midptr = nums.begin() + nums.size() / 2;
    //   nth_element(nums.begin(), midptr, nums.end());
    //   key pnt2: 参考答案：3-way-partition
    //   key pnt3：参考答案：逆序穿插避免中位数首尾相遇！！！
    //   key pnt4：参考答案：优化空间复杂度，使用3-way-partition过程中虚地址方法不实际操作！！！
    void wiggleSort(vector<int>& nums) {
        //  stl 快排
        auto midptr = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // 3-way-partition:将值聚集在中心
        // int i = 0, j = 0, k = nums.size() - 1;
        // while (j < k) {
        //     if (nums[j] > mid) {
        //         swap(nums[j], nums[k]);
        //         --k;
        //     }
        //     else if(nums[j] < mid){
        //         swap(nums[j], nums[i]);
        //         ++i;
        //         ++j;
        //     }
        //     else {
        //         ++j;
        //     }
        // }
        
        // //  insert:逆序穿插避免中位数首尾呼应
        // if (nums.size() % 2) ++midptr;
        // vector<int> tmp1(nums.begin(),midptr);
        // vector<int> tmp2(midptr, nums.end());
        // for (int i = 0;i < tmp1.size(); ++i) {
        //     nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        // }
        // for (int i = 0;i < tmp2.size(); ++i) {
        //     nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        // }

        //  虚地址降低空间利用 使用函数记录空间穿插后的位子
        //  ‘|’为按位或，如果n为偶数，(n|1)为n+1，如果n为奇数，(n|1)仍为n
        // 虚地址记录:使用公式描述映射关系。大在前小在后
        // Accessing A(0) actually accesses nums[1].
        // Accessing A(1) actually accesses nums[3].
        // Accessing A(2) actually accesses nums[5].
        // Accessing A(3) actually accesses nums[7].
        // Accessing A(4) actually accesses nums[9].
        // Accessing A(5) actually accesses nums[0].
        // Accessing A(6) actually accesses nums[2].
        // Accessing A(7) actually accesses nums[4].
        // Accessing A(8) actually accesses nums[6].
        // Accessing A(9) actually accesses nums[8].
        int n = nums.size();
        #define A(i) nums[(1+2*(i)) % (n|1)] 

        // 对虚地址操作
        // 3-way-partition同时完成位置调换！！！！！！！
        // 理解1：在虚拟地址中实现调换后显示的结构满足需求
        // 理解2：对现实点进行操作使其满足相邻的点奇偶拆分后由大到小奇大偶小且中位数在中间 
        //tricky: 由奇数到偶排列保证中位数开头的pair在前面，中位数结尾的pair在后面。
        //顺便完成了逆序穿插的工作。避免了中位数首尾相遇问题！！！！
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
    // Q1:考虑中位数长一位的问题 放后面
    // [1,1,2,1,2,2,1]
    // [1,2,1,2,1,1,2,2,1]
    // Q2:考虑下中位数很多的情况，将中位数在后的挪到最后面
    // 但是有很多情况不能只换一个：参考答案：逆序穿插把front部分要调过来这样才没有相邻可能！！
    // [4,5,5,6]
    // [4,5,5,5,5,6,6,6] [5,6,5,6,5,6,4,5]
    // solution2：改进找中位数，参考答案:快排找一边可以做到O(n)
};
// @lc code=end

