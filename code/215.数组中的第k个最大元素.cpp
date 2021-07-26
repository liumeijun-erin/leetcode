/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //way1:priority_queue
        /*priority_queue<int> q;
        for(int i = 0;i < nums.size();i++){
            q.push(nums[i]);
        }
        for(int i = 1;i < k;i++){
            q.pop();
        }
        return q.top();*/
        //way2:quickSort
        int n = nums.size();
        int target = n - k,l = 0, r = n,pos = 0;
        //改变target减少其它运算时间
        while(l < r){
            pos = quickSort(nums,l,r);
            //cout<<pos<<" "<<r<<" "<<target<<endl;
            if(pos == target) break;
            else if(pos > target){
                r = pos;
            }
            else{
                l = pos + 1;
            }
        }
        return nums[pos];
    }
    int quickSort(vector<int>& nums,int l,int r){
        if(l + 1 >= r) return l;
        int key = nums[l],first = l,last = r - 1;
        while(first < last){
            while(first < last&& nums[last] >= key){
                --last;
            }
            nums[first] = nums[last];
            while(first < last && nums[first] <= key){
                ++first;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        return first;
    }
};
// @lc code=end

