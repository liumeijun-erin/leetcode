# 数学问题

[TOC]

## 公倍数与公因数

* 最大公因数GCD vs 最小公倍数 LCM
  
  * 辗转相除法/欧几里得算法
  
  ```c++
  //辗转相除法/欧几里得算法
  int gcd(int a, int b) {//这里a，b大小顺序无关，可以自动调整；利用gcd(b, a% b)==gcd(a, b)递归
  	return b == 0 ? a : gcd(b, a% b);//递归边界gcd(a,0) = a
      //注意：0和任何数字n的最大公约数都是n
  }
  int lcm(int a, int b) {
  	return a / gcd(a, b) *b; 
      //防止溢出
  }
  ```
  
  * 拓展欧几里得算法：同时得到x，y系数
  
  ```c++
  //拓展欧几里得算法，同时更新系数
  int xGCD(int a, int b, int &x, int &y) {
  	if (!b) {
  		x = 1, y = 0;
  		return a;
  	}
  	int x1, y1, gcd = xGCD(b, a % b, x1, y1);
  	x = y1, y = x1 - (a / b) * y1;
  	return gcd;
  }
  ```
  
  

## 素数/质因数

* 判断是否是素数：O(sqrt(x))

```
//两种循环写法
//for(int i = 2;i * i<= n;i++)//这样应该用double
//for(int i = 2;i<= int(sqrt(n));i++)
```

* 列出素数表：埃氏筛法O(nloglogn)：对于每个素数筛去它的所有倍数；可以在此基础上结合偶数不可能质数以及避免重复搜索等进一步优化，见204可得

* 质因子分解：可以先打印出1-sqrt(n)范围内所有的素数，然后逐一判断并保存个数；最后如果不为零则肯定是一个素数，直接保存即可.

  且由于int最多能表示成10个质数乘积，因此打表最多打10个质数，素数表开到100000就可以了；计数数组长度开到10即可，然后对小于等于sqrt(n)的质数遍历即可。时间复杂度O(sqrt(N)),打表时间视为常数



## 大整数运算

- 注意高低位存储顺序确定好，为了便于运算num[0]存个位比较好，顺位存储；注意string要逆转

- 存储数据结构

  ```c++
  struct bign{
  	int d[1000];
  	int len;
  	bign(){//结构体内部定义构造函数
  		memset(d,0,sizeof(d));
  		len = 0;
  	}
  }
  ```

* bign+bign减法/bign+int除法：注意清掉前面的0的同时保证至少1位

* bign+int 的乘法：可以看作bign的每一位和int整体乘法，再将个位以外的部分全部进位

* bign+int除法：从高低位传递余数r

  

## 随机与抽样

- 随机打乱顺序：Fisher-Yates 洗牌算法，原理是通过**随机交换位置**来实现随机打乱，有正向
  和反向两种写法。注意应该有权不变。leetcode 384

  ```c++
  vector<int> shuffle(vector<int> origin) {
  	if (origin.empty()) return {};
  	vector<int> shuffled(origin);//可以这样赋值
  	int n = origin.size();
  	// 可以使用反向或者正向洗牌，效果相同。
  	// 反向洗牌：
  	for (int i = n - 1; i >= 0; --i) {
  		swap(shuffled[i], shuffled[rand() % (i + 1)]);//想获得这个范围内的随机值，也可以/RAND_MAX再乘范围再round，注意应该是i+1，由留在原地的情况
  	}
  	// 正向洗牌：
  	// for (int i = 0; i < n; ++i) {
  	// int pos = rand() % (n - i);
  	// swap(shuffled[i], shuffled[i+pos]);
  	// }
  	return shuffled;
  }
  ```

  注意如果要同时实现reset和shuffle，应该保留一个origin的复制品或者保留origin原始顺序不变

## 利用数字特点构造抓手

leetcode169-找到多余一半的元素：Boyer-Moore Majority Vote摩尔投票算法