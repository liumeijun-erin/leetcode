/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    void calc(int left,int&right,vector<vector<pair<int,double> > >& tmp,double &ans,double ans_tmp,vector<int>&visited){
        if(left == right) {
            ans = ans_tmp;
            return ;
        }
        for(const pair<int,double> & next:tmp[left]){
            if(visited[next.first]) continue;
            visited[next.first] = 1;
            calc(next.first,right,tmp,ans,ans_tmp*next.second,visited);
            visited[next.first] = 0;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> hash;
        vector<vector<pair<int,double> > > tmp;
        for(int i = 0;i < equations.size();++i){
            int left,right;
            if(hash.count(equations[i][0])) left = hash[equations[i][0]];
            else{
                left = tmp.size();
                tmp.emplace_back(vector<pair<int,double> > {});
                hash[equations[i][0]] = left;
            }
            if(hash.count(equations[i][1])) right = hash[equations[i][1]];
            else{
                right = tmp.size();
                tmp.emplace_back(vector<pair<int,double> > {});
                hash[equations[i][1]] = right;
            }
            if(left == right) continue;
            tmp[left].emplace_back(make_pair(right,values[i]));
            tmp[right].emplace_back(make_pair(left,1.0/values[i]));
        }
        vector<double> res;
        for(const vector<string>& q:queries){
            double ans = -1.0;
            vector<int> visited(tmp.size());
            if(hash.count(q[0])&&hash.count(q[1])){
                int left = hash[q[0]];
                int right = hash[q[1]];
                if(left != right){
                    visited[left]=1;
                    calc(left,right,tmp,ans,1.0,visited);
                    visited[left] = 0;
                }
                else{
                    ans = 1.0;
                }
            }
            res.emplace_back(ans);
        }
        return res;
        //[["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]
        //[["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
    }
};
// @lc code=end

