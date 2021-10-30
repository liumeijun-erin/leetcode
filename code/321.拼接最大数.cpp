/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
    //  very interesting!!!
    // 写到现在唯一彻底不会题。想好在写。20211030
    //参考答案：
    //策略1：利用遍历i+j == k将求最大子序列转换为一维问题降低难度！，所以分别得到两个序列的min(len,k)大子序列
    //note:不要要求一下子构造出最优解，复杂问题可以考虑从一个固定数值关系的角度分情况遍历！！！：如leetcode321拼接最大数，
    //可以遍历两个数组最大子序列长度i+j == k。多算一点中间结果出来反而算法更经济！
    //策略2：经典题型-得到某序列长度为k的最大字典序子序列:单调栈（vector实现）+remain(可跳步数结合)！！！！！
    //tip1:有想到使用jump用来表示不算的次数,但是用来限制遍历i step_width了，复杂，没写出来。
    //！！！直接在pop_back中使用即可以！！！要是想清楚单调栈工作过程应该明白，顺势在过程中+限制！！！！！
    //策略3：merge的时候遇到相同的怎么搞，不要一下子想着整体比较，有逐个思路，先走长的这样下一步可以及时调整！！
    //tip2:样例经典[6,7]\n[6,0,4]\n5考虑两列当前值相同的时候怎么取.详见merge策略！！
    //tip3:分函数书写，拆成单个+merge!
    //tip4:vector比较和赋值待优化
    void getSubSequence(vector<int>& nums, int k,vector<vector<int> >& res) {
        int jump = nums.size() - k;
        for(int i = 0;i < nums.size();++i){
            while(!res[k-1].empty()&&nums[i] > res[k-1].back()&&jump) {
                res[k-1].pop_back();
                --jump;
            }
            res[k-1].emplace_back(nums[i]);
        }
        while(res[k-1].size() > k) res[k-1].pop_back();
    }

    void merge(vector<int>& nums1,vector<int>& nums2,vector<int>& res){
        int i = 0,j = 0;
        int pos = 0;
        //long long res = 0;
        while(i < nums1.size()&&j < nums2.size()){
            //res *= 10;
            if(nums1[i] > nums2[j]){
                res[pos++] = nums1[i++];
            }
            else if(nums1[i] < nums2[j]){
                res[pos++] = nums2[j++];
            }
            else{
                //策略：
                //相同段后大的先取;[6,7] [6,3]
                //一方先到头的话，!!!!让长的先走,之后一切可以再比较，eg [6,1,2],[6]
                //错误思路为比较1和6(到头了从6开始),6大所以行2先走，
                //[1,0,1,1,3]\n[1,0]
                //这种情况就特殊了先走左1,1,0,1,1,3,0;先走右1,1,0,0,1,1,3比较到0处的下一位就应该是0和3比了，而不是最开始的1;而且也不一定是上一位，可能是上上...位，不好确定比较位
                //由答案得：这种情况先走长的，判断的事交给以后
                //想法：!!!!反正如果出现大的就先走，否则最差情况也就是和短的一样！！！！
                int k = 1;
                while(i + k < nums1.size()&&j + k < nums2.size()){
                    if(nums1[i + k] != nums2[j + k]) break;
                    ++k;
                }
                if(i + k < nums1.size()&&j + k < nums2.size()){
                    if(nums1[i + k] < nums2[j + k]) res[pos++] = nums2[j++];
                    else res[pos++] = nums1[i++];
                }
                else if(i + k == nums1.size()) res[pos++] = nums2[j++];
                else res[pos++] = nums1[i++];
                /*int start1 = nums1[i],start2 = nums2[j];
                while(i + k < nums1.size()&&j + k < nums2.size()){
                    if(nums1[i + k] != nums2[j + k]) break;
                    ++k;
                }
                if(i + k < nums1.size()) start1 = nums1[i+k];
                else start1 = nums1[i + k -1];
                if(j + k < nums2.size()) start2 = nums2[j+k];
                else start2 = nums2[j + k - 1];
                if(start1 < start2) res += (nums2[j++]+'0');
                else res += (nums1[i++]+'0');*/
                //cout<<start1<<" "<<start2<<endl; 
            }
            //cout<<res<<endl;
        }
        while(i < nums1.size()) res[pos++] = nums1[i++];
        while(j < nums2.size()) res[pos++] = nums2[j++];
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(),len2 = nums2.size();
        len1 = min(len1,k);
        len2 = min(len2,k);
        vector<vector<int> > res1(len1,vector<int> {}), res2(len2,vector<int> {});
        for(int len = 1;len <= len1;++len) getSubSequence(nums1,len,res1);
        for(int len = 1;len <= len2;++len) getSubSequence(nums2,len,res2);
        vector<int> tmp,max_res(k,-1),tmp_res(k);
        if(len1 == k) merge(res1[len1-1],tmp,max_res);
        for(int i = 1;i <= len1&&i != k;++i){
            if(k-i > len2) continue;
            merge(res1[i-1],res2[k-i-1],tmp_res);
            for(int j = 0;j < k;++j) {
                if(tmp_res[j] > max_res[j]) {
                    max_res.swap(tmp_res);//！tip：参考答案这样快！
                    break;
                }
                else if(tmp_res[j] < max_res[j])  break;//注意这里别忘了!
            }
        }
        if(len2 == k) {
            merge(tmp,res2[len2-1],tmp_res);
            for(int j = 0;j < k;++j) {
                if(tmp_res[j] > max_res[j]) {
                    max_res.swap(tmp_res);
                    break;
                }
                else if(tmp_res[j] < max_res[j])  break;
            }
        }
        return max_res;
    }
    //[2,5,6,4,4,0]\n[7,3,8,0,6,5,7,6,2]\n15
    //[2,0,2,1,2,2,2,2,0,1,0,0,2,0,2,0,2,1,0,1,1,0,1,0,1,2,1,1,1,0,1,2,2,1,0,0,1,2,1,2,2,1,1,0,1,2,0,2,0,1,2,0,2,1,1,1,2,0,0,1,0,2,1,2,0,1,0,0,0,1,2,1,0,1,1,2,0,2,2,0,0,1,1,2,2,1,1,2,2,1,0,1,2,0,1,2,2,0,0,0,2,0,2,0,2,2,0,1,1,1,1,2,2,2,2,0,0,2,2,2,2,0,2,0,1,0,0,2,1,0,0,2,0,2,1,1,1,1,0,1,2,0,2,1,0,1,1,1,0,0,2,2,2,0,2,1,1,1,2,2,0,0,2,2,2,2,2,0,2,0,2,0,2,0,0,1,0,1,1,0,0,2,1,1,2,2,2,1,2,2,0,0,2,1,0,2,1,2,1,1,1,0,2,0,1,1,2,1,1,0,0,1,0,1,2,2,2,0,2,2,1,0,1,2,1,2,0,2,2,0,1,2,2,1,2,2,1,1,2,2,2,2,2,1,2,0,1,1,1,2,2,2,0,2,0,2,0,2,1,1,0,2,2,2,1,0,2,1,2,2,2,0,1,1,1,1,1,1,0,0,0,2,2,0,1,2,1,0,0,2,2,2,2,1,0,2,0,1,2,0]\n[1,1,1,0,0,1,1,0,2,1,0,1,2,1,0,2,2,1,0,2,0,1,1,0,0,2,2,0,1,0,2,0,2,2,2,2,1,1,1,1,0,0,0,0,2,1,0,2,1,1,2,1,2,2,0,2,1,0,2,0,0,2,0,2,2,1,0,1,0,0,2,1,1,1,2,2,0,0,0,1,1,2,0,2,2,0,1,0,2,1,0,2,1,1,1,0,1,1,2,0,2,0,1,1,2,0,2,0,1,2,1,0,2,0,1,0,0,0,1,2,1,2,0,1,2,2,1,1,0,1,2,1,0,0,1,0,2,2,1,2,2,0,0,0,2,0,0,0,1,0,2,0,2,1,0,0,1,2,0,1,1,0,1,0,2,2,2,1,1,0,1,1,2,1,0,2,2,2,1,2,2,2,2,0,1,1,0,1,2,1,2,2,0,0,0,0,0,1,1,1,2,1,2,1,1,0,1,2,0,1,2,1,2,2,2,2,0,0,0,0,2,0,1,2,0,1,1,1,1,0,1,2,2,1,0,1,2,2,1,2,2,2,0,2,0,1,1,2,0,0,2,2,0,1,0,2,1,0,0,1,1,1,1,0,0,2,2,2,2,0,0,1,2,1,1,2,0,1,2,1,0,2,0,0,2,1,1,0,2,1,1,2,2,0,1,0,2,0,1,0]\n600
};
// @lc code=end

