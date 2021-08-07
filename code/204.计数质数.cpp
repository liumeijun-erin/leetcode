/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        //101书上对埃氏筛法有改进！针对偶数和重复遍历
        if(n <= 2) return 0;
        vector<bool> isPrime(n,true);
        int cnt = n/2,sqrtn = int(sqrt(n)),i = 3;
        while(i <= sqrtn){
            //原算法到n，但实际根据j = i^2已经超了，不用在遍历了
            for(int j = i*i;j < n;j += i*2){
                //原算法从2*i开始，但是实际上偶数都可以去掉，且小于i的奇数积也已经遍历过了，只要从i^2开始即可
                if(isPrime[j]){
                    --cnt;
                    isPrime[j] = false;
                }
            }
            do{
                i +=2;
            }while(i <= sqrtn && !isPrime[i]);//避免偶数和重复遍历
        }
        return cnt;
    }
};
// @lc code=end

