/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */

// @lc code=start
class Solution {
    long long mod = 1000000007;
    // key pnt:一个不保险
    long long mul1 = 131;
    long long mul2 = 1227;
public:
    // 有序即可二分+mul1 mul2 mod二重保障更靠谱
    // 本题不会，参考答案 -- 按rk+长度进行遍历+二分！--RK算法一个不保险用两个
    // key pnt:遍历搜索边界 + >= <= 问题都可以用二分，
    // RK算法从len:n-1-1遍历是否有相同子串 -- > 这一步简化，不用一次遍历，而是
    // 利用性质进行二分:!!!想法是利用性质（类似manacher)：重复子串的子串也是重复子串
    int check(vector<int>& arr, int len) {
        int n = arr.size();
        set<pair<long long, long long> > pre_s;
        long long cur1 = 0,cur2 = 0;
        long long front_mul1 = 1, front_mul2 = 1;
        for (int i = 0; i < len; ++i) {
            cur1 = (cur1 * mul1 + arr[i]) % mod;
            cur2 = (cur2 * mul2 + arr[i]) % mod;
            if(i != 0) {
                front_mul1 = (front_mul1 * mul1) % mod;
                front_mul2 = (front_mul2 * mul2) % mod;
            }
        }
        pre_s.insert(make_pair(cur1,cur2));
        for (int i = 1; i + len -1 < n; ++i) {
            cur1 -= (front_mul1 * arr[i-1]) %mod;
            cur2 -= (front_mul2 * arr[i-1]) %mod;
            if(cur1 < 0) cur1 = (cur1 + mod) % mod;
            if(cur2 < 0) cur2 = (cur2 + mod) % mod;
            cur1 = (cur1 * mul1 + arr[i + len -1]) % mod;
            cur2 = (cur2 * mul2 + arr[i + len -1]) % mod;
            if (pre_s.count(make_pair(cur1,cur2))) return i;
            pre_s.insert(make_pair(cur1,cur2));
        }
        return -1;
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        vector<int> arr(n); // tip：先存好char->int省着以后多次分步存
        for (int i = 0;i < n; ++i) {
            arr[i] = s[i] - 'a';
        }
        // tip: 利用性质转化为二分
        int max_len = 0, pos = -1; 
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r-l + 1) / 2;
            int pos_tmp = check(arr, m);
            if (pos_tmp != -1) {
                l = m + 1;
                max_len = m;
                pos = pos_tmp;
            }
            else {
                r = m - 1;
            }
        }
        return pos != -1? s.substr(pos, max_len) : "";
    }

    // solution1-failed: 依次遍历起始点，使用kmp算法超时
    // n * (n+1) - 9*10 ^ 8 超时
    // string longestDupSubstring(string s) {
        // int n = s.length();
        // int pos, max_len = 0;
        // vector<int> p_id(n,0);
        // for (int i = 0; i < n; ++i) {
        //     vector<int> p_id(n,i);
        //     for (int j = i + 1, k = i; j < n; ++j) {
        //         while (k > i && s[k] != s[j]) k = p_id[k-1];
        //         if (s[j] == s[k]) ++k;
        //         p_id[j] = k;
        //         if (p_id[j] - i  > max_len) {
        //             pos = i;
        //             max_len = p_id[j] - i ;
        //             //cout<<max_len<<" "<<pos<<endl;
        //         }
        //     }
        // }
        // if (max_len < 1) return "";
        // return s.substr(pos, max_len);
        // "happappa"
        // "pmyiaxmicpmvqywlkisfzzutlxxjipitwcfxgqqfnxizowkqfmzsvkxryknasyvthozahbmapwqocupxcktmmtddxgatzftamrsvtddjpbnrojcqonmzxmknashplmykdbadiiccdkbyyzifqxvqfwgwihxgnrhqlmqprnjawuzcotutbkgnykuuwtzzzppmoyfmplhpznpnlwwbndekakpsmehzmbcfoyudgwsvehzgsfwqdkihiiwxfskicrbmoevxvpmmymihlkmgnuyohcofzfkehccwxezxypnnvqzrilr"
    // }
};
// @lc code=end

