/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution {
public:
    void help(vector<vector<int>>& special, vector<int>& prices, vector<int> needs,int pos,int sum,int &res){
        if(pos == special.size()){
            for(int i = 0;i < needs.size();++i) {
                if(needs[i] > 0) {
                    sum += needs[i] * prices[i];
                    if(sum > res) return;
                }
            }
            res = min(res,sum);
            return ;
        }
        while(1){
            help(special, prices, needs, pos+1, sum, res);
            bool hasEmpty = true;
            for(int i = 0;i < special[pos].size()-1;++i){
                if(needs[i] < special[pos][i]) {
                    hasEmpty = false;
                    break;
                }
                needs[i] -= special[pos][i];
            }
            if(!hasEmpty) break;
            sum += special[pos][special[pos].size()-1];
            if(sum >= res) break;
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0;
        int n = price.size();
        for(int i = 0;i < n;++i){
            res += price[i] * needs[i];
        }
        help(special, price, needs, 0, 0, res);
        return res;
    }
    //[2,3,4]\n[[1,1,0,4],[2,2,1,9]]\n[1,2,1]
};
//\n
// @lc code=end

