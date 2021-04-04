# 算法笔记Chapter12-字符串提高算法

[TOC]

## 字符串匹配问题：str2是否为str1子串(以leetcode28为例)

### 暴力find：时间复杂度最坏O(len1*len2)

### 滚动哈希Rabin-Karp:最坏O(N/len1+len2)

* 关键在于：常数时间内修改出窗口移动后(长度为len2)的字符子串哈希码，then将窗口内子串hash code与str2比较

* 只有小写英文字母的情况可定义一下coding过程：arr[i] = (int)S.charAt(i) - (int)'a'得到字符串hash

  如*h*0=0×26^3+1×26^2+2×26^1+3×26^0 --"abcd",len2=4

  注意避免溢出：具体见下字符串hash部分

* 每次窗口移动 *h*1 = *h*0 % 26^3 × 26 + X×26^0 //常数时间

* 具体实现见leetcode28

  

## 字符串hash

* 核心：将string映射为整数，以便搜索/比较（str比较速度<<int比较速度）

* 公式1：求string的hash code

  H[i] = (H[i-1] * p + index(str[i])) % mod
  * 实践发现进制数和mod分别是10^7\10^9级别的素数时冲突概率极小，不易产生冲突

  即 H[i] = (H[i - 1] * p + index(str[i])) % mod，其中p可取10000019, mod 可取1000000007

  * 例题：N个字符串求不同字符串数目：先str->int，再set/map可以提高速度

* 公式2：求子串的hash code
  * 法1：(通用)  H[i..j] = ((H[j] - H[i - 1] * p^(j - i + 1) )% mod + mod) % mod
    
    * 注意mod can be tricky 要加mod避免负数
    *  p^(j - i + 1) 可专门用p[len]保存
  * 法2：用于固定长度子串，如leetcode28求str2是否是str1子串（Rabin-karp方法）

    * H[i,len2 + i - 1] = (((H[i - 1,len2 + i - 2] - (p^(len2 - 1)  * index(str[i - 1])%mod) + mod) % mod) * p % mod + index(str[i + len - 1])

      重点在于可以O(1)修改得到窗口内子串的hash code，然后hash(窗口)和hash(str2)两两比较

    * ```
      const LL MOD = 1000000007;
      const LL P = 10000019;
      const LL MAXN = 1010;//字符串最大长度
      LL powP[MAXN],H1[MAXN];
      ```

  * 例题：
    
    * 求两个字符串最长公共子串：算好H1，H2，按长度依次递减先计算str1子串hash code，再算str2子串hash code 同时比较是否已有
    
    * 最长回文子串：hashcode+二分法 O(nlogn）
    
      算好string hashcode数组H1，再算string_reverse 的hashcode数组H2--O(n)
    
      分奇偶情况：遍历中心点i和长度k（可用二分法确定，因为长回文包括短回文），对比对应段的hashcode --O（nlogn）
    
      personal：也可先遍历k再i，实际效果说不定好

* 避免冲突两种方法:

  * p mod取较大素数p = 10000019，mod = 1000000007

  * 双hash法，使用两个p1 = 10000007，p2 = 10000019得到两个数pair，一个pair对应一个str

    ...

* 还有其他字符串hash函数，不只进制转换..

























