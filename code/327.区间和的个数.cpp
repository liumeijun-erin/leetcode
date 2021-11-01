/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
public:
    //！！！参考答案：(1)归并排序找子段！！！(2)线段树遍历区间的用法！！！
    //参考答案：https://leetcode-cn.com/problems/count-of-range-sum/solution/qu-jian-he-de-ge-shu-by-leetcode-solution/
    //还可以手动实现平衡二叉树，没做出来
    //！！！solution1：归并排序，如何在控制i<j的情况下找到合适的位置。利用两个数组！！！
    //使用递归！！！左右分段分别内部解决之后判断左i-右j是否可以！！！这样可以控制i<j条件
    //T(n) = O(n/2)+2T(n/2)->O(nlogn)
    //solution2:线段树可以实现O(logn)查询和插入！！！详见题解
    //以所有pre_sum前缀和取值范围为l-r区间基地，在区间范围上统计、保存：查询该范围内的节点数
    //线段树：统计区间，这里以取值范围为区间！
    //详见答案:
    //(1)可以先求max——min然后离散化确定范围-build(确定所有) insert count
    //也可以这里long long 随时插入-insert,count
    //动态插入节点的模板
    /*struct SegNode {
        long long lo, hi;
        int add;//针对lo和hi上的统计量
        SegNode* lchild, *rchild;
        SegNode(long long left, long long right): lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
    };  

    class Solution {
    public:
        void insert(SegNode* root, long long val) {
            root->add++;
            if (root->lo == root->hi) {
                return;
            }
            long long mid = (root->lo + root->hi) >> 1;
            if (val <= mid) {
                if (!root->lchild) {
                    root->lchild = new SegNode(root->lo, mid);
                }
                insert(root->lchild, val);
            }
            else {
                if (!root->rchild) {
                    root->rchild = new SegNode(mid + 1, root->hi);
                }
                insert(root->rchild, val);
            }
        }

        int count(SegNode* root, long long left, long long right) const {
            if (!root) {
                return 0;
            }
            if (left > root->hi || right < root->lo) {
                return 0;
            }
            if (left <= root->lo && root->hi <= right) {
                return root->add;
            }
            return count(root->lchild, left, right) + count(root->rchild, left, right);
        }

        int countRangeSum(vector<int>& nums, int lower, int upper) {
            long long sum = 0;
            vector<long long> preSum = {0};
            for(int v: nums) {
                sum += v;
                preSum.push_back(sum);
            }
            
            long long lbound = LLONG_MAX, rbound = LLONG_MIN;
            for (long long x: preSum) {
                lbound = min({lbound, x, x - lower, x - upper});
                rbound = max({rbound, x, x - lower, x - upper});
            }
            
            SegNode* root = new SegNode(lbound, rbound);
            int ret = 0;
            for (long long x: preSum) {
                ret += count(root, x - upper, x - lower);
                insert(root, x);
            }
            return ret;
        }
    };

*/
    //实现build,insert，count！
    //以前缀和取值范围[x-lower，x-upper]为线段，存储其中的节点数量
    //线段树用法--统计一段区间内的和/平均值。参考桶排序的思路，可以遍历y结果/遍历x...区间内节点可变：可以实现O（logn)查询和插入，可以保存l，r，sum。leetcode327
    //其他solution：线段树，前缀树，手动实现二叉平衡树..
    int help(vector<long long>& dp,int& lower,int& upper,int l,int r) {
        if(l == r) return 0;
        int mid = (r - l)/2 + l;
        int res = help(dp,lower,upper,l,mid);
        res += help(dp,lower,upper,mid+1,r);
        //!!!两边内部计算完可以开始sort
        sort(dp.begin()+l,dp.begin()+mid+1);
        sort(dp.begin()+mid+1,dp.begin()+r+1);
        int i = l,j = mid + 1,k = mid + 1;
        while(i <= mid&&dp[j] - dp[i] > upper) ++i;
        //cout<<i<<" "<<mid<<" "<<j<<endl;
        while(i <= mid){
            while(j <= r&&dp[j] - dp[i] < lower) ++j;
            while(k <= r&&dp[k] - dp[i] <= upper) ++k;
            res += (k - j);
            ++i;
        }
        return res;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //思路1-没做出来：先保存前缀和，然后遍历的时候对当前和之前的进行排序
        //希望插入:O(LogN),二分查找上下界也是O(LogN).。需要手动实现平衡二叉树
        vector<long long> dp(nums.size());
        int cnt = 0;
        for(int i = 0;i < nums.size();++i){
            if(i == 0) dp[0] = nums[0];
            else dp[i] = dp[i-1] + nums[i];
            if(dp[i] >= lower &&dp[i] <= upper) ++cnt;
        }
        return cnt + help(dp,lower,upper,0,dp.size()-1);
        //[2147483647,-2147483648,-1,0]\n-2\n0
        //[0]\n0\n0
        //[0,0]\n0\n0算3次可重复
        //[0,-1,-2,-3,0,2]\n3\n5
        //[-3,2,-2,1,2,-3]\n-6\n-5
    }
};
// @lc code=end

