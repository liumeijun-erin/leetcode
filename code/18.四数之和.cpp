/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    //本题极大混乱,待优化：事先想好结构（怎样循环+重复数值怎么保存）再写比查缺补漏强多了了
    //参考答案：双指针+剪枝.固定一头，另一头遍历！;
    //分析-由于这种有数值关系限制，因此可以两边制约进行双指针，不用无脑dp！!这种问题不能用dp，有很多重复性计算！！！！
    //tip1:note！明确right含义，搜索边界而不是固定边界
    //tip2:剪枝细节，及时break
    //tip3:判断时用/而不用*,容易越界!!
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size() <= 3) return res;
        unordered_map<int,int> hash;
        for(const int& n:nums){
            if(hash.count(n)) ++hash[n];
            else hash[n] = 1;
        }
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.size()-1;
        while(left + 3 <= right){
            if(nums[left] > target/4) break;
            else if(4 * nums[left] == target){
                if(hash[nums[left]] >= 4) {
                    res.emplace_back(vector<int> {nums[left],nums[left],nums[left],nums[left]});
                }
                break;
            }
            while(left + 3 <= right && 3 * nums[left] + nums[right] > target) --right;
            if(left + 3 > right) break;
            if(hash[nums[left]] >= 3){
                int tmp = target - 3 * nums[left];
                if(hash.count(tmp)) {
                    res.emplace_back(vector<int> {nums[left],nums[left],nums[left],tmp});
                }
            }
            if(hash[nums[left]] >= 2){
                int tmp = target -  2*nums[left];
                for(int i = left + hash[nums[left]];i < right; i += hash[nums[i]]){
                    if(tmp < 2*nums[i]) break;
                    else{
                        if(tmp != 2*nums[i]&&hash.count(tmp-nums[i])||tmp == 2*nums[i]&&hash[nums[i]] >= 2) {
                            res.emplace_back(vector<int> {nums[left],nums[left],nums[i],tmp - nums[i]});
                        }
                    }
                }
            }
            for(int i = left + hash[nums[left]];i + 1 < right;i += hash[nums[i]]){
                int tmp = target - nums[left];
                if(nums[i] > tmp/3) break;
                else if(3*nums[i] == tmp){
                    if(hash[nums[i]] >= 3) {
                        res.emplace_back(vector<int> {nums[left],nums[i],nums[i],nums[i]});
                    }
                    break;
                }
                if(hash[nums[i]] >= 2){
                    tmp -= 2*nums[i];
                    if(tmp > nums[i]&&hash.count(tmp)) {
                        res.emplace_back(vector<int> {nums[left],nums[i],nums[i],tmp});
                    }
                }
                tmp = target - nums[left] - nums[i];
                for(int j = i + hash[nums[i]];j < right;j += hash[nums[j]]){
                    if(tmp < 2*nums[j]) break;
                    else if(tmp == 2 * nums[j]){
                        if(hash[nums[j]] >= 2) {
                            res.emplace_back(vector<int> {nums[left],nums[i],nums[j],nums[j]});
                        }
                        break;
                    }
                    if(hash.count(tmp - nums[j])) {
                        res.emplace_back(vector<int> {nums[left],nums[i],nums[j],tmp - nums[j]});
                    }
                }
            }
            left += hash[nums[left]];
        }
        return res;
        //[0,0,0,1000000000,1000000000,1000000000,1000000000]\n1000000000
        //[-1,2,2,-5,0,-1,4]\n3
        //[91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245]\n-236727523
    }
};
// @lc code=end

