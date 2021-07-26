# 算法笔记Chapter6、7-STL&数据结构

[TOC]

# Chapter6 - STL

## +queue,map,set,string方法汇总小结：

**queue：**push, front, back, pop, empty, size

**map：**find, erase, size, clear, insert, count,empty

**set：**find, erase,size, clear, insert, count, empty

**string：**=/+=/关系运算符length/size/insert/erase substr, find, replace, size, length

注意：vector中没有find

## vector 变长数组

* 常用于：

  * 变长数组
  * vector<int> adj[N]; #邻接表存图

* 头文件： #include<vector>

* 定义：vector<typename> name;

  vector<vector<int> > name; #二维vector数组

  vector<typename> arrayname[arraysize];  

* 访问：

  * 下标 vi[index]

  * 迭代器 vector<int> ::iterator iter = vi.begin();printf("%d",*(iter+i)) 

    #iter只能iter++/--或者*(iter+1)->这种用法只有vector和string有，不能iter = iter + 2

    ```C++
    for(vector<int>::iterator iter = vi.begin();iter != vi.end();iter++){
    
    	print("%d",*iter);#注意不是< vi.end()
    }
    ```

* 自带函数：

  * v.push_back(x) # 时间复杂度O(1)

  * v.pop_back() # 时间复杂度O(1)

  * v.size() # 时间复杂度O(1)

  *  v.clear() # 时间复杂度O(n)

  * v.insert(iter,x) # vi.insert(vi.begin()+2,-1) 第三位为-1,时间复杂度O(n)

  * v.erase(iter) # 删除iter位置,时间复杂度O(n)

    v.erase((iter1,iter2) # 删除区间，注意左闭右开！,时间复杂度O(n)



## string 字符串

- 头文件： #include<string> #不同于cstring/string.h

- 定义：string str; # 可以初始化

- 读写整个字符串：只能cin/cout；用printf把str.c_str()输出

- 访问元素：

  - string[index]

  - 迭代器！ 

    string::iterator iter;#*iter得到元素

    #支持*(iter+n)

- 自带函数：

  - +/+= 

  - 字典序比较 < ,>,<=,>=,==,!=

  - length/size #str.length()/str.size(),时间复杂度O(1)

  - insert,时间复杂度O(N)

    - str1.insert(pos,str2) # str1[pos]处插入str2,即从第4位[3]开始为str2
    
  - str1.insert(iter1,iter21,iter22)
  
- erase,时间复杂度O(N)
  
    - str.erase(iter)
    - str.erase(iter1,iter2)
    - str.erase(pos,length)
    - PS.str erase干净之后不能用，不是“”
    
  - clear #str.clear(),时间复杂度O(1)

    - PS.str clear之后不能用，不是“”

  - substr() #返回子串, str.substr(pos,len),时间复杂度O(len)

  - string::npos #实际等于-1/unsigned_int中max

    #用于string find，注意string find不返回iter

  - str.find(str2) #如果是子串，返回第一个pos；否则string::npos,时间复杂度O(len1*len2)

    - 还有rfind
  
  - replace,时间复杂度O(str1.length())
  
    - str1.replace(pos,len,str2)
    - str1.replace(it1,it2,str2)
  
  * 有的标准还有back，pop_back等



## set 集合：内部自动有序且不含重复元素

- 常用于自动去重且排序，结果自动增序！

  前提是没有重复！

  只排序不去重复可以使用multiset；

  只去重不排序可以使用unordered_set。#使用散列代替红黑树实现，much faster

- 头文件： #include<set>

- 定义：set<typename> name;

  set<vector<int> > name; #vector集合

  set<typename> arrayname[arraysize];  #set数组

- 访问：

  - 只能迭代器！ 

    set<int> ::iterator iter;#*iter得到元素

    #不支持*(iter+1)只能枚举

    ```C++
    for(set<int>::iterator iter = s.begin();iter != s.end();iter++){
    
    	print("%d",*iter);#结果自动增序！因为内部红黑树实现。可以设置优先级见下。
    }
    ```

- 自带函数：

  - s.insert(x) # 时间复杂度O(logN)

  - find #返回迭代器,时间复杂度O(logN)

    iter = s.find(n) #注意如果不存在，应该是s.end()。注意判断。

  - erase
    - erase删除单个元素:
      - s.erase(iter) # 时间复杂度O(1)
      - s.erase(value) # 时间复杂度O(logN)
    - erase删除区间元素:
  	  - s.erase(iter1,iter2) # 时间复杂度O(iter2-iter1)

  - s.size() # 时间复杂度O(1)
  
  - s.clear() # 时间复杂度O(N)
  
    
  

## map 字典/映射

- 常用于建立不同数据类型之间的映射，结果自动增序！

  前提是一对一 ！

  一对多可以使用multimap；

  只映射不排序可以使用unordered_map #使用散列代替红黑树实现，much faster

- 头文件： #include<map> 

- 定义：map<typename1,typename2> mp;

- 访问元素：

  - map[key]

  - 迭代器 map<typename1,typename2>::iterator iter;

    #iter->first,iter->second/(* iter).first,(* iter).second得到key、value

    #注意key值自带顺序，由小至大。可以设置优先级见下。

- 自带函数：

  - find,时间复杂度O(logN)

    iter = mp.find(key)

  - erase

    - mp.erase(iter) #时间复杂度O(1)
    - mp.erase(key) #时间复杂度O(logN)
    - mp.erase(iter1,iter2) #左闭右开，时间复杂度O(iter2-iter1)

  - size #mp.size(),时间复杂度O(1)

  - clear #mp.clear(),时间复杂度O(N)

  - insert #mp.insert(make_pair(a,b))
  
  - count #有key返回1，无key返回0
  
  - size



## queue 队列

- 常用于：BFS

  此外地还有双端队列deque（两端可删插）、优先队列priority_queue(由堆实现，保证最大优先值置于首位)

- 头文件： #include<queue>

- 定义：queue<typename> name;

- 访问：只能访问首尾,不能用下标取值

  - q.front() #注意使用之前必须用q.empty判空！
  - q.back() #注意 尾元素也可以！不是end，是back！

- 自带函数：

  - q.push(x) # 时间复杂度O(1)
  - q.pop() # 时间复杂度O(1)，注意使用之前必须用q.empty判空！
  - q.empty() #返回true/false，时间复杂度O(1)
  - q.size() # 时间复杂度O(1)
  - q.front()
  - q.back()



## priority_queue 优先队列/堆heap

- 原理：由heap堆实现，将列中优先级最高的置于队首

- 常用于：贪心问题，对Dijkstra算法优化（本质heap，不用历次找max/min）

- 头文件： #include<queue>

- 定义（优先级设置）：set map也有，详见下方

  - 基本数据类型的优先级设置，数字/字典序大的优先级高
    - priority_queue<typename> q;  # 两种写法相同含义
    - priority_queue<typename，vector<typename> ,less<int> > q; # less表示最大的在最前面，注意顺序！
    - priority_queue<typename，vector<typename> ,greater<int> > q; #greater表示最小的在最前面

  * 结构体的优先级设置

    * way1：要重载overload <，然后priority_queue<structname>  q;即可

      ```C++
      struct fruit{
      	string name;
      	int price;
      	bool operator < (fruit f1,fruit f2){ #注意重载>会出错，无论大还是小的优先都应重载<
      		return f1.price < f2.price; # 这里使用<还是>决定大的优先还是小的优先！
      	}
      }
      
      priority_queue<fruit> q;#这样的是大的优先
      
      #return f1.price > f2.price;
      #priority_queue<fruit> q;#这样的是小的优先
      
      #tip：结构体过大的时候可以在传参的时候使用const fruit &f1,const fruit &f2引用，提高效率
      ```

      然后priority_queue<structname>  q;即可

    * way2：写成结构体外面的cmp函数定义优先级，再定义priority_queue（基本数据类型、其他STL也可以这么定义)

      ```C++
      struct cmp{
      	bool operator ()(fruit f1,fruit f2){
      		return f1.price > f2.price;#现在是最小的在前，注意与sort的cmp方向相反
      	}
      }
      priority_queue<fruit,vector<fruit> ,cmp> q;
      #tip：结构体过大的时候可以在传参的时候使用const fruit &f1,const fruit &f2引用，提高效率
      ```

- 访问：不能访问队尾,只能访问队首/堆顶元素（优先级最高者）

  - q.top() # 注意使用前先判空

- 自带函数：

  - q.push(x) # 时间复杂度O(logN)
  - q.pop() # 时间复杂度O(1)，注意使用之前必须用q.empty判空！
  - q.empty() #返回true/false，时间复杂度O(1)
  - q.size() # 时间复杂度O(1)
  - q.top() #注意是top不是front



## stack 栈

- 常用于：（少）使用栈模拟实现递归，防止递归（几千/万层）超出程序栈空间

- 头文件： #include<stack>

- 定义：stack<typename> name;

- 访问：只能访问栈顶,不能用下标取值

  - s.top() 

- 自带函数：

  - s.push(x) # 时间复杂度O(1)
- s.top() # 时间复杂度O(1)
  - s.pop() # 时间复杂度O(1)
- s.size() # 时间复杂度O(1)
  - s.empty()# 时间复杂度O(1)

* PS.STL stack 没有clear操作，如果清空只能不停pop，空间允许的时候应该直接建立新stack，faster

## + set，map，priority_queue的优先级设置

set<int> s;//默认升序,相当于 set<int,less<int> >。
set<int,less<int> > s; //该容器是按升序方式排列元素。
set<int,greater<int>> s;  //该容器是按降序方式排列元素。

map<T1,T2> m;*//默认按键的升序方式排列元素,相当于下方的less*
map<T1,T2,less<T1> > m; *//该容器是按键的升序方式排列元素。*
map<T1,T2,greater<T1>> m;  *//该容器是按键的降序方式排列元素。

priority_queue<int> p; //默认降序， 大顶堆，队头元素最大
priority_queue<int, vector<int>, less<int> > p; //相当于默认
priority_queue<int, vector<int>, greater<int>> p; //升序，最小值优先级队列，小顶堆

## + iterator迭代器

```C++
type::iterator iter；#正序遍历

for(iter = n.begin(); iter != n.end();iter++){} 

type::reverse_iterator iter;  #反序遍历

for(iter = n.rbegin();iter !=  n.rend();iter++)
```



## + pair

* 实际等于

  ```C++
  struct pair{
      typename1 first;
      typename2 second;
  }
  ```

* 常用语：代替二元结构体，节省定义时间；作为map键值对

  #mp.insert(make_pair(a,b)) 等价于mp[a] = b

* 头文件： #include<utility> /如果有#include<map>则不用单独写，（包含关系）

* 定义：

  * pair<typename1,typename2> p;
  * pair<typename1,typename2> p(a,b);初始化
  * 赋值
    * p = pair<typename1,typename2>(a,b)
    * p = make_pair(a,b)

* 访问元素：p.first,p.second

* 比较：可用<,>,<=,>=,==,!=,原理为先比first再比second

  ​	

## + algorithm 头文件常用函数

### max(x,y)，min(x,y)，abs(x)（整型，浮点绝对值fabs需要cmath头文件）

#注意max，min二元 #max(max(a,b),c)

### swap(x,y)

### reverse(iter1,iter2) /reverse(index1,index2)

#注意左闭右开

#int a[]数组和stl均可

### next-permutation：将当前排列改成在全排列中的下一个排列

```c++
int a[10] = {1,2,3};
do{
    printf("%d %d %d\n",a[0],a[1],a[3])
}while(next_permuatation(a,a+3));#当321时返回false
```

### fill：数组/容器某一段赋任意相同值（memset只有0，-1）

### sort：对数组/容器（vector，deque，string）排序

#原地修改 不用a = sort（a...

#sort(a,a+10) 左闭右开，且默认从小到大/字典序

#sort(a,a+10,cmp)

```C++
bool cmp(typename a,typename b){
	return a>b;#这样从大到小
}

bool cmp(structname a,structname b){
	return a.value<b.value;#定义结构体排序，注意<对应升序
}

bool cmp(structname a,structname b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y; #定义二级排序
}
```

### lower_bound & upper_bound:在有序数组/容器中找第一个符合要求的数

返回指针\迭代器，想要index还可以将返回值-a/s.begin

lower_bound(first,last,val) #找第一个>=val的位置，没有则返回可插入该元素的位置！！，复杂度(O(log(last-first)))

upper_bound(first,last,val) #找第一个>val的位置，没有则返回可插入该元素的位置！！，复杂度(O(log(last-first)))



# Chapter7 - 其它数据结构

## stack（用数组/链表实现栈）

#### TOP标记栈顶元素，初始-1

* clear: TOP = -1
* size: return TOP + 1 
* empty: return TOP == -1
* push:  st[++TOP] = x
* pop: TOP-- #注意判空
* top:return st[TOP] #注意判空