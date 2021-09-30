/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    void bp(vector<int>& cb,int& res,int level){
        //注意对角线也不可
        if(level == cb.size()) {
            ++res;
            return;
        }
        for(int i = 0;i < cb.size();++i){
            if(cb[i] != -1) continue;
            bool possibleMove = true;
            for(int j = 0;j < cb.size();++j){
                if(cb[j] == -1) continue;
                if(abs(cb[j]-level) == abs(j-i)){
                    possibleMove = false;
                    break;
                }
            }
            if(possibleMove){
                cb[i] = level;
                bp(cb,res,level+1);
                cb[i] = -1; 
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> cb(n,-1);//record by col
        int res = 0;
        bp(cb,res,0);
        return res;
    }
};
// @lc code=end

