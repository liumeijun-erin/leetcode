/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        //hash-table O(N) O(N)
        //modify1:use nums.size instead of 300
        //key pnt1:understand only numbers in [1,len] matter
        //key pnt2:a prejudgement is needed to avoid hash-table index overflow 
        //question:does it satisfy the requirement (use space O(const)/O(1))? No
        int min = 0x7fffffff;
        //vector<int> hash(nums.size() + 1);
        int hash[301] = {0};
        for(int i = 0;i < nums.size();i++){
            if(nums[i] <= 0) continue;
            if(nums[i] < min) min = nums[i];
            if(nums[i] <= nums.size()) hash[nums[i]] += 1;
        }
        if(min != 1){
            return 1;
        }
        int j;
        for(j = 1;j <= nums.size();j++){
            if(hash[j] == 0){
                break;
            }
        }
        return j;*/
        /*
        //tip1:use existing array!!!!! as hash-table--brilliant:use sign - to tag visited!!!
        //O(N) O(1)
        //key pnt1 and pnt2 same as above
        //key pnt3 dont forget abs() && abs(-0x7fffffff)
        //note: consider cases with duplicate numbers 
        if(nums.size() == 0) return 1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] <= 0 || nums[i] == 0x7fffffff) nums[i] = nums.size() + 1;
        }
        int i;
        for(i = 0; i < nums.size();i++){
            if(abs(nums[i]) <= nums.size() && nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for(i = 0;i < nums.size();i++){
            if(nums[i] > 0) {
                break;
            }
        }
        return i + 1;
        */
       ///*
       //tip2:use existing array as hash-table:swap nums to form:nums[i] = i
       //note1: consider cases with duplicate numbers,especially when nums[i]== nums[nums[i] - 1]
       //key pnts:always watch out for endless loop! e.g.[1,1],[1,2,5,4,5]
       if(nums.size() == 0) return 1;
       for(int i = 0;i < nums.size();i++){
           //while(nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums.size()){
            while(nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]){
                swap(nums[i],nums[nums[i] - 1]);
            }     
       }
       for(int i = 0;i < nums.size();i++){
           if(nums[i] != i + 1) return i + 1;
       }
       return nums.size() + 1;
    }
};
// @lc code=end

