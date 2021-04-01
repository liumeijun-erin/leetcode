# 算法笔记Chapter6-STL

[TOC]

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



## set 集合：内部自动有序且不含重复元素

- 常用于自动去重且排序，结果自动增序！

  前提是没有重复！

  只排序不去重复可以使用multiset；

  只去重不排序可以使用unordered_map。

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
    
    	print("%d",*iter);#结果自动增序！
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
  
    
  

## string 

- 常用于

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

    iter = s.find(n)

  - length/size #str.length()/str.size(),时间复杂度O(1)

  - insert,时间复杂度O(N)

    - str1.insert(pos,str2) # str1[pos]处插入str2,即从第4位[3]开始为str2
    - str1.insert(iter1,iter21,iter2)
    
- erase,时间复杂度O(N)
	
	  - str.erase(iter)
	  - str.erase(iter1,iter2)
    - str.erase(pos,length)
  
  - clear #str.clear(),时间复杂度O(1)
  
  - substr() #返回子串, str.substr(pos,len),时间复杂度O(len)
  
  - string::npos #实际等于-1/unsigned_int中max
  	
  	#用于string find，注意string find不返回iter
  	
  - str.find(str2) #如果是子串，返回第一个pos；否则string::npos,时间复杂度O(len1*len2)
  
  - replace,时间复杂度O(str1.length())
  
    - str1.replace(pos,len,str2)
    - str1.replace(it1,it2,str2)
