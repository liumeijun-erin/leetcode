/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    //note1:O(NlogN),doesnot meet requirements
    /*struct cmp{
      	bool operator ()(pair<int,int> p1,pair<int,int> p2){
      		return p1.second > p2.second;
      	}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //tip1:maintain a size-k heap O(Nlogk) at most,and min at top!
        vector<int> res;
        unordered_map<int,int> m; //tip:faster
        priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> q;
        for(int i = 0;i < nums.size();i++){
            if(m.find(nums[i])!=m.end()) m[nums[i]] += 1;
            else m[nums[i]] = 1;
        }
        for(unordered_map<int,int>::iterator it = m.begin();it !=m.end();it++){
            if(q.size() < k){    
                q.push(make_pair(it->first,it->second));
            }
            else if(it->second > q.top().second){
                q.pop();
                q.push(make_pair(it->first,it->second));
            }
            //cout<<it->first<<" "<<it->second<<endl;
        }
        for(int i = 0;i < k;i++){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }*/
    int quickSort(vector<pair<int,int> > &p,int low,int high){
        //note:note spcial situation ,like 1,2,3;2,2,2
        //use:always check if index >= array.len before use it!!!!avoid overflow!!
        int count = p[low].second;
        while(low <= high){
            while(low <= high && p[low].second >= count) low++;
            while(high>= 0 && p[high].second < count ) high--;
            if(low < high) {
                swap(p[low],p[high]);
                low++;
                high--;
            }
        }
        return low;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //tip2:use quick sort,O(N)
        unordered_map<int,int> m; //tip:faster
        for(int i = 0;i < nums.size();i++){
            if(m.find(nums[i])!=m.end()) m[nums[i]] += 1;
            else m[nums[i]] = 1;
        }
        vector<pair<int,int> > p;
        for(unordered_map<int,int>::iterator it = m.begin();it !=m.end();it++){
            p.push_back(make_pair(it->first,it->second));
            cout<<it->first<<" "<<it->second<<endl;
        }
        vector<int> res;
        int low = 0;
        int high = p.size() - 1;
        int pos = 0;
        while(k > 0){
            pos = quickSort(p,low,high);
            //cout<<pos<<" "<<low<<" "<<high<<" "<<endl;
            if(pos - low > k){
                high = pos - 1;
                low = low + 1;
                //note:pretty tricky
            }
            else {
                for(int i = low;i <pos ;i++){
                    res.push_back(p[i].first);
                }
                k-= (pos - low);
                low = pos;
            }
        }
        return res;
    }
};
// @lc code=end

