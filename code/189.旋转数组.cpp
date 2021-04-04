/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    /*
    // O(k*n),O(n^2/2) worst
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0){
            return ;
        }
        k = k % nums.size();
        int n;
        if(k == 0){
            return;
        }
        else if(k < nums.size()/2){
            while(k--){
                n = nums[nums.size()-1];
                nums.pop_back();
                nums.insert(nums.begin(),n);
            }
        }
        else{
            k = nums.size() - k;
            while(k--){
                n = nums[0];
                nums.erase(nums.begin());
                nums.push_back(n);
            }
        }
    }*/
    //tip1:手画过程，依次后移，k个一组，将不冲突的并行
    //O(n)
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1){
            return ;
        }
        k = k % nums.size();
        if(k == 0){
            return ;
        }
        int count = 0;
        for(int i = 0;i < k;i++){
            int tmp = nums[i];
            int j = i + k;
            do{
                swap(tmp,nums[j % nums.size()]);
                count += 1;
                j += k;
            }while(j % nums.size() != i);
            swap(tmp,nums[j % nums.size()]);
            count += 1;
            if(count == nums.size()){
                break;
            }
        }
    }
    /*
    //tip2:rotate vector
    //O(n),翻转数组，仍原地修改，但快好多
    void reverse(vector<int>& nums,int a,int b){
        for(int i = a;i <= (b + a)/2;i++){
            int tmp = nums[i];
            nums[i] = nums[a+b-i];
            nums[a+b-i] = tmp;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1){
            return ;
        }
        k = k % nums.size();
        if(k == 0){
            return ;
        }
        reverse(nums,0,nums.size() - 1);
        reverse(nums,0,k - 1);
        reverse(nums,k,nums.size() - 1);
    }*/
};
// @lc code=end

