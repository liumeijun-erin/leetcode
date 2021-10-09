/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
class SummaryRanges {
    vector<vector<int> > res;
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        int left = 0,right = res.size();
        //这个地方写了很久很久很久。。。
        //二分条件！！！
        while(left < right-1){
            int mid = (right - left)/2 + left;
            if(res[mid][0] == val||res[mid][0] < val&&res[mid][1] >= val) return;
            if(res[mid][0]>val) right = mid;
            else if(res[mid][1] < val) left = mid+1;//注意这里的条件好好写！要找第一个范围大于等于的
        }
        if(left<res.size()){
            if(res[left][0] > val){
                res.insert(res.begin()+left,vector<int> {val,val});
            }
            else  if(res[left][1] >= val) return;
            else if(res[left][1] == val-1){
                res[left][1] = val;
            }
            else{
                res.insert(res.begin()+left+1,vector<int> {val,val});
                ++left;
            }
        }
        else{
            res.emplace_back(vector<int> {val,val});
            left= res.size()-1;
        }
        if(left+1<res.size()&&res[left][1] + 1 == res[left+1][0]){
            res[left][1] = res[left+1][1];
            res.erase(res.begin()+left + 1);
        }
        if(left-1>0&&res[left-1][1] + 1 == res[left][0]){
            res[left-1][1] = res[left][1];
            res.erase(res.begin()+left);
        }
    }
    
    vector<vector<int>> getIntervals() {
        return res;
    }
    //["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n[[],[49],[],[97],[],[53],[],[5],[],[33],[],[65],[],[62],[],[51],[],[100],[],[38],[],[61],[],[45],[],[74],[],[27],[],[64],[],[17],[],[36],[],[17],[],[96],[],[12],[],[79],[],[32],[],[68],[],[90],[],[77],[],[18],[],[39],[],[12],[],[93],[],[9],[],[87],[],[42],[],[60],[],[71],[],[12],[],[45],[],[55],[],[40],[],[78],[],[81],[],[26],[],[70],[],[61],[],[56],[],[66],[],[33],[],[7],[],[70],[],[1],[],[11],[],[92],[],[51],[],[90],[],[100],[],[85],[],[80],[],[0],[],[78],[],[63],[],[42],[],[31],[],[93],[],[41],[],[90],[],[8],[],[24],[],[72],[],[28],[],[30],[],[18],[]]
    //["SummaryRanges","addNum","getIntervals","addNum","getIntervals"]\n[[],[1],[],[0],[]]
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

