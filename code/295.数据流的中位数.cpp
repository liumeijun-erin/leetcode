/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
    //本题不会：试图使用线段树维护--还没有实现。太蠢了。主要被100迷
    //经典问题：直观思考存两边
    //考虑其他数据结构巧妙解决：利用两个有序队列实现找中位数！！！！
    //经典问题：大顶堆小顶堆动态求中位数！！！直观思考：分界分两边存储！！！
    //分析：不在中间取值，有序取头尾即可。priority_queue完美！
    //pq2：存大于等于当前中位数的，小的开始
    //pq1：存小于当前中位数的，大的开始

    // 改进：只在求平均的时候来回转换，平时不维持
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int> > pq2;
    
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
       if (!pq2.empty() && num >= pq2.top()) pq2.emplace(num);
       else pq1.emplace(num);
    }
    
    double findMedian() {
        while (pq1.size() < pq2.size()) {
            int tmp = pq2.top();
            pq2.pop();
            pq1.emplace(tmp);
        }
        while (pq1.size() > pq2.size() + 1) {
            int tmp = pq1.top();
            pq1.pop();
            pq2.emplace(tmp);
        }
        if (pq1.size() == pq2.size()) return (pq1.top() + pq2.top()) / 2.0;
        return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

