/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    //way1：使用vector保存位置超时
    //note：类里面写cmp需要static、or使用[](){}
    //way2:使用map<int,vector<int>>但是超级慢
    //改进:multimap注意到有重复值
    //不要忽略改进数据结构这回事！！！！：需要排序+映射+有重复值->multimap！
    static bool cmp(int a,int b){
        return a>b;
    }
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end(),cmp);
        multimap<int,int,greater<int> > hash;
        //注意默认从小到大
        for(int i = 0;i < nums2.size();++i){
            //hash[nums2[i]] = i;
            //multimap好像不能这么用
            hash.insert(make_pair(nums2[i],i));
        }
        vector<int> res(nums1.size());
        int i = 0,j =nums1.size() - 1;
        for(auto p:hash){
            //cout<<p.first<<endl;
            if(p.first < nums1[i]) res[p.second] = nums1[i++];
            else res[p.second] = nums1[j--];
        }
        return res;
    }
    //way3：使用<pair,pair>结构的vector，将位序号在一起
    /*vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int,int> > new_nums2;
        for(int i = 0;i < nums2.size();++i){
            new_nums2.push_back(make_pair(nums2[i],i));
        }
        sort(new_nums2.begin(),new_nums2.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.first > b.first;});
        sort(nums1.begin(),nums1.end(),[](const int &a,const int &b){return a>b;});
        vector<int> res(nums1.size(),0);
        int i = 0,j = nums1.size()-1;
        for(auto p:new_nums2){
            if(p.first < nums1[i]){
                res[p.second]= nums1[i++];
            }
            else{
                res[p.second]= nums1[j--];
            }
        }
        return res;
    }*/

};
// @lc code=end

