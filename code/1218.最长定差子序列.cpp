/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> hash;
        int res = 1;
        for(const int& a:arr){
            if(!hash.count(a)) hash[a] = 1;
            if(hash[a] > res) {
                res = hash[a];
                //cout<<a<<endl;
            }
            hash[a + difference] = hash[a] + 1;
            //hash.erase(a);
           
        } 
        return res;
        
    }
    //[4,12,10,0,-2,7,-8,9,-9,-12,-12,8,8]\n0
};
// @lc code=end

