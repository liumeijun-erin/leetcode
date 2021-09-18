/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

// @lc code=start
class Solution {
public:
    //  分两种情况：当前所有都大于before-before外展；一旦有一个小于等于即内旋
    bool isSelfCrossing(vector<int>& distance) {
        if(distance.size()<=3) return false;
        bool bigger = (distance[2]>distance[0]);
        for(int i = 3;i < distance.size();i++){
            if(distance[i] == distance[i-2]){
                if(bigger) {
                    distance[i-1] -= distance[i-3]; 
                    bigger = false;
                }
                else return true;
            }
            else if(distance[i] < distance[i-2]){
                if(bigger){
                    bigger = false;
                    if(i>=4&&distance[i] + distance[i-4]>=distance[i-2]){
                        distance[i-1] -= distance[i-3];
                    }
                }
            }
            else{
                if(!bigger) return true;
            }
        }
        return false;
        //[3,3,4,2,2]
    }
};
// @lc code=end

 