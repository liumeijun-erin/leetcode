/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
public: 
    //left+right滑动双指针/sliding window
    //  优化：不再遍历当前unordered_map看是否符合条件，而是补充一个变量记录
    // tip1:使用中间变量记录结果，避免遍历
    int longestSubstring(string s, int k) {
        if(k == 1) return s.size();
        vector<int> cnt_letter(26),cnt(s.size());
        for(int i = 0;i < s.size();++i){
            ++cnt_letter[s[i]-'a'];
            cnt[i] = cnt_letter[s[i]-'a'];
        }
        int right = s.size()-1,left = right;
        int len = 0;
        while(right + 1 >= k){
            while(right + 1 >= k&&cnt[right] < k) --right;
            if(right + 1 < k) break;
            unordered_map<char,int> hash;
            int qualified = 0;
            left = right;
            while(left >= 0){
                if(hash.count(s[left])){
                    if(hash[s[left]] == k-1) ++qualified; 
                    ++hash[s[left]];
                    --left;
                }
                else if(cnt[left] >= k)  {
                    //tip2:由样例得，中间结果可能为res-bcbbaaa\n3
                    if(qualified == hash.size()) len = max(len,right - left);
                    hash[s[left]] = 1;
                    --left;
                }
                else break;
            }
            //cout<<left<<" "<<right<<" "<<qualified<<endl;
            if(qualified == hash.size()) len = max(len,right - left);
            --right;//tip3：注意right = left - 1不对
        }
        return len;
        //"ababbc"\n2
        //"bchhbbdefghiaaacb"\n3
        //"ababacb"\n3
        //"aaabbbcdefcdefgggggggggggggggcde"\n3
        //"cbcbbaaa"\n3
        //"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\n1
    }
};
// @lc code=end

