/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    struct cmp{
        bool operator ()(pair<long long,pair<int,int> > a, pair<long long,pair<int,int> > b){
            return a.first > b.first;
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //quite tricky!
        //solution1:
        //tip1:use priority_queue
        //tip:consider time limit
        //tip:when the array is ordered,there's no need to use set to avoid duplicate numbers
        //tip:maybe add a set can get faster or maybe not
        /*priority_queue<long long,vector<long long>,greater<long long> > q;
        q.push(1);
        long long num ;
        while(n--){
            num = q.top();
            while(!q.empty()&&q.top() == num) q.pop();
            for(int i = 0;i < primes.size();i++){
                q.push(num * primes[i]);
            }
        }
        return (int)num;*/
        //solution2:just like 373
        //so use pair<int,int> :pair<value1,index>
        //note:be aware of duplicate numbers:
        //for example:25\n[3,5,7,17,19,23,29,43,47,53]
        //5 * 5 * 3 and 5 * 3 * 5
        //so use pair<long long,pair<int,int> >:value lowIndex highIndex to avoid duplicate and to reduce space usage
        //主要思想就是：使用范围乘法控制重复入栈；每次出栈顶之后在范围内都更新一遍top保证左右可能min都在栈中
        if(n == 1) return 1;
        n--;
        priority_queue<pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > >,cmp> q;
        for(int i = 0;i < primes.size();i++){
            q.push(make_pair(primes[i],make_pair(0,i)));
        }
        while(--n){
            int maxIndex = q.top().second.second;
            int minIndex = q.top().second.first;
            for(int i = minIndex;i <= maxIndex;i++){
                q.push(make_pair(q.top().first*primes[i],make_pair(i,maxIndex)));
            }
            q.pop();
        }
        return (int)q.top().first;
    }
};
// @lc code=end

