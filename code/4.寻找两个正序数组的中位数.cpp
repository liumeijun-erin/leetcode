/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // tip:充分利用len1 + len2 == k/2的关系
    // 一边遍历另一边index可以确定然后筛选
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //solution1:思路挺好，预处理也挺好，但是想的不全面，随着测试用例走，一直在堵窟窿而不是疏通。
        //先预估一下问题的复杂度，否则过于理想化O(n^2)/O(nlogn).所以两层二分O(logn^2)也可接受->O(logm*logn)
        //思路：先二分一个数组，然后再二分第二个数组直到左侧的数都小于它，这样计算cnt与(m+n)/2比较，再进行更新
        //！！！重点是定好各个量之后的意义就不再变化！
        //note:考虑所有可能测试用例，如[1]\n[2] vs [2]vs[1]
        /*if (nums1.size() < nums2.size()||nums1.size()==nums2.size()&&nums1[0] > nums2[0]) swap(nums1,nums2);
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
            if(mid1 + mid2 + 1>= num){
                //目标：mid1 + mid2之前元素有num/元素
                if(mid2 == 0||mid1>= num&&nums2[0] >= nums1[num-1]||mid1 + 1>= num&&nums2[0] >= nums1[num-1]){
                    //全在nums1上取
                    mid1 = num;
                    mid2 = 0;
                    break;
                }
                else if(num-mid1-2>=0&&nums2[num - mid1-2] == nums2[mid2-1]){
                    //nums1上取到mid1
                    mid2 = num - mid1-1;
                    ++mid1;
                    break;
                }
                else if(mid1 <= num&&num-mid1 - 1<n&&(num - mid1 >= n||nums2[num - mid1] >= nums1[mid1-1])){
                    //nums1上取mid1之前
                    //mid1和mid2前面的为num/2
                    mid2 = num-mid1 ;
                    break;
                }
                right1 = mid1;
                right2 = mid2;
                left2 = 0;
            }
            else{
                left1 = mid1 + 1;
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
            //cout<<"2results:"<<tmp<<" "<<res<<endl;
            res = res + (tmp - res)*1.0/2;
            //note：这里1.0*(tmp-res)/2显示的仍然整数除法，不深究了，记住即可
        }
        return res;
        */
        //solution2!!!:try不要第二层循环会发生什么，解法2不要第二层循环根据个数
        //思路：利用一端序号已经固定，对一个进行遍历
        if(nums1.size() > nums2.size()) swap(nums1,nums2);
        int m = nums1.size(),n = nums2.size();
        int num = m + (n - m)/2;
        //note:!!!这里如果m = 1，n = 2会出错，这样求均值的时候注意m>=n!!
        int left = 0,right = m,mid;
        //两侧闭区间,mid代表取mid前所有值
        while(left <= right){
            //cout<<"left-right:"<<left<<"-"<<right<<endl;
            mid = left + (right - left)/2;
            if(num - mid > n) {
                left = mid + 1;
            }
            else if(mid != m && nums2[num - mid - 1] > nums1[mid]) {
                left = mid + 1;
            }
            else if(num - mid < n && mid >= 1&& nums2[num - mid] < nums1[mid - 1]) {
                right = mid - 1;
            }
            else break;
        }
        int l1 = mid -1,r1 = mid,l2 = num - mid - 1,r2 = num - mid;
        double res1;
        if(r1 < m&&r2<n) res1 = min(nums1[r1],nums2[r2]);
        else if(r1 < m) res1 = nums1[r1];
        else res1 = nums2[r2];
        //cout<<"res1:"<<res1<<endl;
        //cout<<(m+n)%2<<endl;
        //注意:这里不能写成!(m+n)%2,应该是!((m+n)%2)
        if(!((m+n)%2)) {
            double res2;
            if(l1 >= 0&&l2>=0) res2 = max(nums1[l1],nums2[l2]);
            else if(l1 >= 0) res2 = nums1[l1];
            else res2 = nums2[l2];
            //cout<<"res2:"<<res2<<endl;
            res1 = (res1 + res2)/2.0;
        }
        return res1;
    }
};
// @lc code=end

