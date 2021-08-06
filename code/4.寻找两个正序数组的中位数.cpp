/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //先预估一下问题的复杂度，否则过于理想化O(n^2)/O(nlogn).所以两层二分O(logn^2)也可接受->O(logm*logn)
        //思路：先二分一个数组，然后再二分第二个数组直到左侧的数都小于它，这样计算cnt与(m+n)/2比较，再进行更新
        //！！！重点是定好各个量之后的意义就不再变化！
        if (nums1.size() < nums2.size()) swap(nums1,nums2);
        int m = nums1.size(),n = nums2.size();
        //左闭右开区间
        int num = n + (m-n)/2;
        int left1 = 0,right1 = m,mid1;
        int left2 = 0,right2 = n,mid2;
        while(left1 < right1){
            mid1 = left1 + (right1 - left1)/2;
            while(left2 < right2){
                //返回mid2是第一个大于nums1[mid1]的位序
                mid2 = left2 + (right2 - left2)/2;
                if(nums2[mid2] <= nums1[mid1]) left2 = mid2 + 1;
                if(nums2[mid2] > nums1[mid1]) right2 = mid2;
            } 
            mid2 = left2;
            cout<<mid1<<" "<<mid2<<endl;
            if(mid1 + mid2>= num){
                //目标：mid1 + mid2之前元素有num/元素
                if(mid2 == 0||mid1 >= num&&nums2[0] >= nums1[num-1] ){
                    //全在nums1上取
                    mid1 = num;
                    mid2 = 0;
                    break;
                }
                else if(num-mid1-1>=0&&nums2[num - mid1-1] == nums2[mid2-1]){
                    //nums1上取到mid1
                    ++mid1;
                    mid2 = num - mid1;
                    break;
                }
                else if(mid1<= num&&nums2[num - mid1] >= nums1[mid1-1]){
                    //nums1上取mid1之前
                    //mid1和mid2前面的为num/2
                    mid2 = num-mid1 + 1 ;
                    break;
                }
                right1 = mid1;
                right2 = mid2;
                left2 = 0;
            }
            else{
                left1 = mid1;
                left2 = mid2;
                right2 = n;
            }
        }
        double res;
        if(mid1 != m &&mid2 != n) res = min(nums1[mid1],nums2[mid2]);
        else if(mid1 != m) res = nums1[mid1];
        else res = nums2[mid2];
        if((m + n)%2 == 0){
            int tmp;
            if(mid1 >0 && mid2 > 0) tmp = max(nums1[mid1-1],nums2[mid2-1]);
            else if(mid1 > 0) tmp = nums1[mid1-1];
            else tmp = nums2[mid2-1];
            cout<<"2results:"<<tmp<<" "<<res<<endl;
            res = res + (tmp - res)*1.0/2;
            //note：这里1.0*(tmp-res)/2显示的仍然整数除法，不深究了，记住即可
        }
        return res;
        //不要第二层循环会发生什么，解法2不要第二层循环根据个数
    }
};
// @lc code=end

