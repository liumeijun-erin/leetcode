/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution {
public:
    /*struct cmp{
        bool operator()(vector<int> a,vector<int> b){
            return (a[0]+a[1]) > (b[0]+b[1]);
        }
    };*/
    struct cmp{
        bool operator()(const pair<int,pair<int,int> >& a,const pair<int,pair<int,int> >& b){
            return (a.first+a.second.first) > (b.first+b.second.first);
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //solution1:really slow O(NKlog(NK))
        /*vector<vector<int> > res;
        priority_queue<vector<int>, vector<vector<int> >,cmp> q;
        for(int i = 0;i < nums1.size();i++){
            for(int j = 0;j < nums2.size();j++){
                vector<int> num = {nums1[i],nums2[j]};
                q.push(num);
            }
        }
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
            if(--k <= 0) break;
        }
        return res;*/
        //solution2:https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/solution/8ms-100ji-lu-wei-zhi-zhi-zhen-kuai-su-qiu-jie-by-d/
        //use priority_queue as an array with a fixed length and also maintain its min value
        //tip1:use array and order to accelerate process
        //tip2：use pair<index in array one,index in array two>,update index2 each time
        //note:tip2 face the problem of passing parameters,so use pair<int,pair<int,int> > :pair<value1,pair<value2,index2> >
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,cmp> q;
        //tip3:swap n1,n2 may accelerate process,when n1 is much longer than n2
        int swapFlag = 0;
        if(nums1.size() > nums2.size()){
            swapFlag = 1;
            swap(nums1,nums2);
        }
        for(int i = 0;i <nums1.size();i++){
            q.push(make_pair(nums1[i],make_pair(nums2[0],0)));
        }
        vector<vector<int> > res;
        while(k--){
            if(q.empty()) break;
            if(!swapFlag) res.push_back({q.top().first,q.top().second.first});
            else res.push_back({q.top().second.first,q.top().first});
            if(q.top().second.second < nums2.size() - 1){
                q.push(make_pair(q.top().first,make_pair(nums2[q.top().second.second + 1],q.top().second.second + 1)));
            }  
            q.pop();
        }
        return res;
    }
};
// @lc code=end

