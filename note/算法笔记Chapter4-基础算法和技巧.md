# 算法笔记Chapter4-基础算法和技巧

[TOC]

## tip：散列/哈希hash

* 实现：unordered_set/unordered_map
* 把元素（key）转换（散列函数H）为整数（唯一标识），然后把这个整数用作**数组下标**进行操作
* 一种空间换时间策略：主要利用数组下标可直接访问!
* 散列函数：
  * 直接定址（原数/线性变换）
  * 平方取中（平方值中间若干位）
  * 除留余数（%mod -mod素数）
* 冲突处理：开放定址（对应位置被占用的时候新位置计算开放定址）/链地址法
  * 线性探查法
  * 平方探查法
  * 链地址法
* 字符串hash: 转化为26/52/62进制数/拼接（方法不限，只要能唯一标识即可）

​	可以用类封装vector实现一个简单hash，重点在于 contains，insert，remove和hash函数书写，例如：

```C++
template <typename T>
class HashTable {
	private:
	vector<list<T>> hash_table;
	// 哈希函数
	int myhash(const T & obj) const {
		return hash(obj, hash_table.size());
	}
	public:
	// size最好是质数
	HashTable(int size=31) {
		hash_table.reserve(size);//分配空间，更改capacity但是不改变size
		hash_table.resize(size);//分配空间，同时改变capacity和size
        //：reserve接收一个参数，表示预留空间的大小；resize可以接收两个参数：分配空间的大小和要加入的新元素的值，如果第二个参数被省略，那么就调用元素对象的默认构造函数。
	}
	~HashTable() {}
	// 查找哈希表是否存在该值
	bool contains(const T & obj) {
		int hash_value = myhash(obj);
		const list<T> & slot = hash_table[hash_value];
		std::list<T>::const_iterator it = slot.cbegin();
		for (; it != slot.cend() && *it != obj; ++it);
			return it != slot.cend();
	}
	// 插入值
	bool insert(const T & obj) {
		if (contains(obj)) {
			return false;
	}
	int hash_value = myhash(obj);
	std::list<T> & slot = hash_table[hash_value];
	slot.push_front(obj);
	return true;
	}
	// 删除值
	bool remove(const T & obj) {
		list<T> & slot = hash_table[myhash(obj)];
		auto it = find(slot.begin(), slot.end(), obj);
		if (it == slot.end()) {
			return false;
		}
		slot.erase(it);
		return true;
	}
};
// 一个简单的对整数实现的哈希函数
int hash(const int & key, const int &tableSize) {
	return key % tableSize;
}
```



## tip：前缀和积分图

一维的前缀和，二维的积分图，都是把每个位置之前的一维线段或二维矩形预先计算、存储。存于哈希/列表/数组。

提前计算保留中间结果，空间换时间。可结合动态规划



## tip：双指针

* 本质：利用本身有序的特性！！增加限制，以较低的复杂度解决问题。快速排序、归并排序等可以看做广义双指针应用。

* 同向vs反向：

  同向-**滑动窗口**，**快慢指针** ...

  反向-常用来搜索有序序列,如633，在有序序列上查找两个值要能联想到双指针

  一个数组vs多个数组

* PS.指针 vs 常量

  ```c++
  const int * p2 = &x; // 指针可以被修改，值不可以被修改（const int）
  int * const p3 = &x; // 指针不可以被修改（* const），值可以被修改
  const int * const p4 = &x; // 指针不可以被修改，值也不可以被修改
  ```

* PS.指针 vs 函数

  指针函数：返回指针的函数

  函数指针：指向函数的指针

  ```c++
  int subtraction(int a, int b) {
  	return a - b;
  }
  int operation(int x, int y, int (*func)(int, int)) {//接受函数指针
  	return (*func)(x,y);
  }
  int (*minus)(int, int) = subtraction;//函数指针可以用函数名赋值
  int n = operation(3, 5, minus);
  ```

#### 模板1：快慢指针判圈法fast走两步，slow走一步142



## 分治与递归

* 分治:
  * **分解**为不重叠的子问题
  * **解决**子问题（常递归思想解决，但非必须）
  * **合并**子问题的解
  
* 分治 VS 减治
  * 减治 decrease and conquer：子问题数为1
  * 分治divide and conquer：子问题数大于1
  
* 分治 VS 动态规划
  * 分治：解决**不重叠**的子问题。思想：从上到下的划分然后合并
    * 遇到F(n) = F(n-1)+F(n-2)这种F(n-1)与F(n-2)都固定值不是动态相关+有重复计算的问题可以结合memoization(记忆化搜索：保存中间结果）技术优化
  * 动态规划：解决**重叠**子问题，思想从下至上
    * 从下至上计算F(n) = F(n-1)+F(n-2)
  
* 递归

  * 对于无头绪的排列组合问题，可以思考最简单暴力的方法遍历所有可能方法（详见算法笔记全排列问题，n皇后问题）。过程中可以使用hashtable记录已经作出的决策，每种可能遍历完恢复hashtable即可。

    可结合回溯剪提高效率。

#### 模板2：递归遍历+剪枝回溯 --解决全排列/n皇后问题（算法笔记P115)



## 贪心

* 适用于满足**最优子结构**（即一个问题的最优解可以由子问题的最优解构造出来）的最优化问题

* 严谨过程：想到策略，反证（假设策略不能导致最优解）证明策略正确性，数学归纳法证明全局最优

  一般过程：自己想好就试一试...

* 区间贪心

个人小结：贪心--将全局最优问题转化为满足局部限制/几个方面策略即可。



## 二分

* 根本在于在**一定有序范围**内搜索邻接点，且应该**有确定的临界条件**：如第一个大于/最后一个小于等于（如木棒切割问题，问要求得到至少k个长度相同的木棒前提下长度相同的木棒最长有多长？->可转化为可得到木棒数>=k的最后一个L，对L在范围内搜索）

* step1：明确参数区间表示含义：左开右闭/左闭右闭/...

* step2:循环条件while:根据问题本身和参数区间含义确定left <= right)/left<right，还要看只有一个数字的时候是否还要判断

* step3:更新mid写成a + (b-a)/2

* step4:更新左区间/右区间：[a,mid-1],[mid+1,b]开区间闭区间根据问题形式都可以选择，但要注意统一格式

* step5:判断出口结果，返回left/right

* 常用tip：**如果问题无明确先保持一种习惯，如写左闭右开区间+考虑最后只有1/2/没有点的极限情况，不可以再换用左闭右闭等**

* note：初始区间要覆盖所有结果--如果判断元素是否存在/如果不存在返回应该在的位置区间不同，数组中插入位子则应该[0,n]多一个

  

