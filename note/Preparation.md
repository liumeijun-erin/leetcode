# 算法笔记Chapter1&2-Preparation

[TOC]

## 1.入门

### (1)熟悉Dev-C++环境（11.23）

- 修改背景色
- 新建项目
- 设置断点调试/debug

  - 下一步next line：执行下一行C++语句，遇函数也当做一行语句执行
  - 单步进入into function：执行下一行C++语句，遇函数则进入函数单步执行
  - 下一条语句next instruction和进入语句into instruction同理，只是它们的粒度是汇编语句
  - 跳过continue：执行到下一个断点前
  - 跳过函数skip function：当在函数内部时运行到函数结束停止
  - 添加查看add watch：添加监测的变量，也可以在左侧调试栏中添加监控变量名

- 整段缩进/取消缩进，整段注释/取消注释...：编辑-缩进/tab，编辑-取消缩进/shift+tab
- 设置缩进空格数
- 插入：时间，文件头...

### (2)Github入门

..官方教程

### (3)vscode配置C++(&python)环境+入门

...有收藏

## 2.C++基础语法

### (1)Basic concepts(11.24)

#### 	#note1:刷题时评测结果和处理技巧：	

- 答案正确AC
- 编译错误CE: 先看是否选错语言
- 答案错误WA：先看是否多输出了调试信息
- 运行超时TLE：先计算最坏时间复杂度，若不至于超时则某处可能进入死循环；若否，则降低时间复杂度
- 运行错误RE：many possible reasons。3 common ones：段错误（非法访问内存：数组越界，指针乱指...），浮点错误（/0，%0）,递归时层数过深爆栈。
- 内存超限MLE：数组太大等
- 格式错误PE：输出格式不对，可能多个空格或者换行符等
- 输出超限OLE：输出大量调试信息，或有输出的部分出现了死循环

#### #note2:scanf和printf比cin，cout快，且cout和printf不能混用：

头文件：

```
#include<cstdio>//与#include<stdio.h>等价，c~在C++中更常用
```

格式：

```C++
scanf("%d",&d);
printf("%d",d);
```

#### 	#note3:头文件总结：（待续写...）

```c++
#include<iostream>//cin cout...
#include<cstdio>//or #include<stdio.h> 输入输出scanf，printf,getchar,putchar,gets,puts
#include<cmath>//or #include<math.h>
#include<cstring>//or #include<string.h> memset strlen strcmp strcpy strcat sscanf sprintf
#include<algorithm>//fill max
#include<iomanip>//setprecision
using namespace std;//cin cout等函数

int main(){//C,C++必须有main函数

	return 0;
}
```

#### #note4：一定要先预估时间&空间复杂度，考虑OJ系统限制！循环：10^7-10^8次运算以内;空间：1MB 262144个int，256MB 67108844个int 

OJ系统中运算速度一般10^7-10^8次/秒 

eg.**O(n^2) -->n规模1000一般可以**,运算复杂的时候也不可以需要优化操作，如优化邻接表等;

​						**10000有时可以**

​	**O(n^3) -->n规模上限100**

空间一般256MB，67108844个int，**`int[N][N]` N=10000时不可**

空间

**预估之后勿忘：空间换时间/时间换空间策略**

#### #note5:审题是否多点测试&多点测试三种输入格式：

- 读到文件结束:

  - while scanf+！EOF

    while(scanf("%d",&n)!=EOF){//scanf返回读取参数的个数EOF（-1）表示文件无法读取,
    }

    while(scanf("%d%d",&a,&b)!=EOF){
    }

    while(scanf("%s",str)!=EOF){
    }

  - while(gets(str)!=NULL){

    }

- while break

  如条件：a b均为0时结束

  - while(scanf("%d%d",&a,&b)!=EOF){

    ​	if(a == 0 && b == 0) break;

    }

  - while(scanf("%d%d",&a,&b)!=EOF,a||b){

    }

- while(t--){}组数已知

### (2)基本数据类型（11.24）

#### 	#note6:各数据类型的大小和范围:确定类型时不能只看赋值和结果值的范围，还要保证大于中间过程值的最大范围！整数必要时也可以赋float double！浮点数直接选double即可！

- #### A 整型（输出：int%d，long long%lld）

​	short:略 

​	int/long int :4Byte32bit , -2^31~2^31-1(-2147483648~2147483647) , 约为-2\*10^9~2\*10^9

​	long long/long long int:8Byte64bit, -2^63~2^63-1, 约为-9\*10^18~9\*10^18

​	unsigned int： 0~2^32-1

​	unsigned long long：0~2^64-1

​	note:

​		long long型赋超过int范围的值时要加LL，防止编译错误	

```
	long long bignum = 123456789012345LL;
```

​	note：可以用**typedef**起别名

```c++
	typedef long long ll;
​	ll a;
```

- #### B 浮点型（输出：float和double都是%f,输入有区别：%f，%lf)

​	float  4Byte32bit(1bit符号8bit指数23bit尾数) , -2^128~2^128, 有效精度6-7位

​	double  8Byte64bit(1bit符号11bit指数52bit尾数) , -2^1024~2^1024, 有效精度15-16位

​	note:指数位有符号；由2^23十进制7位得精度6-7位，double同理

​			尽量都选double，8765.4*8765.4用float之后整数部分都不准确

- #### C 字符型（输出：%c字符，%s字符串）

​	char：1Byte -128~127 

​		note:小写字母比大写字母asc码值大32，字符常量用‘括起来

​	转义字符：\0的asc码为0,代表null 

​		note:printf（“%c”，7）//不输出7，含义是asc码为7

​	字符串：两种表示方式

​		字符数组：详见2(1)数组B字符数组

```C++
char s[25] = "Hello World!";//note:字符数组可以用printf("%s",s);方法输出
```

​		string（C++特有）

```C++
#include<string>
string s = “Hello World!";//note:string类不能用scanf读取也不能用printf输出
```

- #### D 布尔型

​	bool:0 false/1 true

​	note：非零值自动转true，eg1，-1...

#### 	#note7:整型/整型得到整数，应该类型转换(double)a/(double)b

- #### E 符号常量以及const常量：赋值后无法改变

符号常量(宏定义/宏替换)：注意先替换后编译运行

```C++
#define pi 3.14//note：没有；
#define ADD(a,b) ((a)+(b))//还可以定义语句和片段，但是要注意能加的地方都加()

#define CAL(x) (x*2+1)
int a = 1;
cout<<CAL(a+1)<<endl;//得到4

#define MAX(a,b) ((a)>(b)?(a):(b))//宏定义函数
```

const常量

```C++
const double pi = 3.14;//有数据类型和;
```

#### #note8:经过容易损失精度的运算后/进行临近定义域边界的运算前，如判断是否为0/浮点数比较/sqrt(x) x->0/asin(x) x->1/acos(-1) x->-1时需要用eps(1e-8)控制：

​	如asin等运算

```C++
const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)-(b)) < (eps)) //判等 返回true/false 
#define More(a,b) ((a)-(b)>(eps))//判大于
#define Less(a,b) ((a)-(b)<(-eps))//判小于
#define MoreEqu(a,b) ((a)-(b) > (-eps))//判大于等与
#define LessEqu(a,b) ((a)-(b) < (eps))//判小于等与

#const double Pi = acos(-1.0);//精确Pi值
```

​	**sqrt(x) x->0/asin(x) x->1/acos(-1) x->-1等运算前需要用eps保证变量在定义域范围内。**

​	还有的编译环境返回-0.00，可以保存在字符串中然后于“-0.00”比较，对比成功再用ep修正。

### (3)运算符（11.24）

- 算数运算符   

  note:**整数除法返回整数,但-15/4得到-3与floor(-15.0/4)不同**；注意除数是否为0

  ps 负号与减号不同 负号优先级高于除号

- 关系运算符

- 逻辑运算符 note：&& ||区分python 的and 和or

- 条件运算符 ？：唯一的三目运算符

- 位运算符 <<左移，>>右移，&位与，|位或，^位异或（相同为0，不同为1），~位取反

#### #note9：无穷大INF通常定义为0x3fffffff/2^30-1避免相加超过int的范围

int 上限2^31 - 1 0x7fffffff但通常定义INF为2^30 - 1

```C++
const int INF = （1<<30) - 1;//注意括号，否则先减
const int INF = 0x3fffffff;//等价
```

### (4)逻辑结构（11.24）

- 顺序结构 note：n=m=5可以

- 选择结构

  - if  //if(n!=0)等价if(n) f(n==0)等价if(!n)

  - switch 

    switch(x){

    ​	case a: 

    ​				;

    ​		break;

    ​	...

    ​	default:

    }

- 循环结构

  - while //while(n) while(!n)与前同

  - do...while

    note：do{}while();后面有;

  - for

### (#note10/5)输入输出小结（11.24）

- scanf&printf

  头文件：#include<cstdio>

  scanf（“整个输入的格式“，&...):

  A &取地址符号，只有读取字符数组时不用

  B 输出：float和double都是%f,输入有区别：%f，%lf

  **C scanf无法读有空格或多行字符串，scanf中（除了%c以外）都以空格和换行为结束判断标志，无法读有空格或多行字符串；但是可用%c读取其中的换行符或者空格**

  ```c++
  scanf(“%d%d”,&a,&b);//输入3 4即可
  ```

  scanf printf字符串中都可以有转义字符

```c++
	printf("&&");//output&
	printf("\\");//output\
```

​		printf输出格式小结：

​			%md：右对齐 位数不足则高位空格补全，超过则不变
​			%-md：左对齐

​			%0md：右对齐，0补全

​			%.mf:保留m位小数

​					note：**四舍六入五成双**原则：尾数==5：后面均为零的时候看前一位奇进偶舍；不均为零则进

​					若要**四舍五入**需要round结合移位or #include<iomanip>

​			%m.nf

- getchar&putchar输入/输出字符

  头文件：#include<cstdio>

  ```c++
  c1 = getchar();//用法1
  getchar();//用法2：接受不想要的字符
  putchar(c1);//别忘了写参数
  ```

- gets&puts

  头文件：#include<cstdio>

  gets：输入一行字符串，识别换行符\\n作为结束，存于字符数组中

  puts：输出字符数组并**自动跟一个换行**

  ```C++
  gets(str1);
  puts(str1);
  ```

  **note：使用gets前一定要看前面是否有没有吸收掉的\n，如果有，用getchar()吸收**

- cin&cout

  ​	头文件：#include<iostream> using namespace std;

  - **字符数组:可以直接输入输出，但是不能读入空格**

    ​	cin会自动带'\0'

    ```C++
    char str[100];
    cin>>str;
    cout<<str;
    ```

    ​	**要读入空格，需要getline**

    ```C++
    cin.getline(str,100);//读入一整行
    ```

  - **字符串STL string：同样可以直接输入输出，但不能读入空格**

    ​	**要读入空格，需要getline**

    ```C++
    string str;
    getline(cin,str);
    ```

  - 小数：可以四舍五入输出 #include<iomanip> cout<<fixed<<setprecision(2)<<n<<endl;

- getline

  最后会自动补全'\0'

  ```C++
  cin.getline(str,len);//读有空格的字符数组
  getline(cin,str);//读string容器
  ```

- sscanf&sprintf:

  头文件：#include<cstring>

  note:这里str为字符数组

  理解：实际scanf(screen,"%d",&n)->sscanf(str,"d"，&n) sprintf同

  ```C++
  //字符串处理实例：
  int n；
  char str[100]="123";
  sscanf(str,"%d",&n);//n==123
  
  int n = 123;
  char str[100];
  sprintf(str,"%d",n);//str="123"
  
  char str[100]="2048:3.14,Hello"
  sscanf(str,"%d:%lf,%s",&n,&db,str2);//note:字符数组不用&
      
  同理
  sprintf(str,"%d:%lf,%s",n,db,str2);//note:str不用&
  ```

- 小结：小数输出

  - printf+%m.nf四舍六入五成双

  - 使用round + /配合完成四舍五入

  - cout+setprecision 

    cout<<fixed<<setprecision(2)<<n<<endl;

- 小结：字符数组输入输出

  ​	**note：scanf gets cin(getline)会自动在末尾‘\0’，其它输入方法需要手动+‘\0'，否则puts和printf会出错**

  - scanf&printf：

    %c 识别字符，且可读空格或换行

    **%s 读字符串，以空格或换行结束（不包括）**

  - getchar&putchar

    note：常用getchar()吸收掉不想要的空格或者换行！

  - gets&puts

    可读空格，以换行为结束

    **note：gets前(间)要保证没有空格；**

  - sscanf&sprintf

  - cin&cout 不能读入空格和换行 cin.getline(str,len);可以读一行

- 小结：string输入输出

  - cin&cout //note:有空格的读入：getline(cin,str)

### (6)cmath库函数（11.24）

​	note：都是针对double

```c++
#include<cmath>
```

- fabs(x) //返回double

- abs(x)//返回int

- floor(x) ceil(x) //返回都是double型,有的编译器需要%.0f输出 ;-5.2向下是-6 -52向上-5;

  note:

  ```c++
  cout<<floor(-15/4)<<endl;//-3
  cout<<floor(-15.0/4.0)<<endl;//-4
  cout<<-15/4<<endl;//-3
  cout<<-15.0/4.0<<endl;//-3.75
  ```


- pow(double r,double p)

- sqrt(double x)

- log(double x)

- sin(double x),cos(double x),tan(double x) //要求x弧度制

  note：

  ```C++
  const double pi = acos(-1.0)//精确定义pi
  ```

- asin(double x),acos(double x),atan(double x) //返回也是弧度制

- round(double x) //四舍五入，返回也是double

### (7)函数参数(11.25)

- 值传递：形参实参，不改变原来的值


#### 	#note11:数组做为函数参数，第一维不需要写长度，其它维要写；函数中修改是对原数组元素的修改；数组不能作为函数返回类型！

```C++
void change(int a[],int b[][5]){//note:也可以穿length
	a[0] = 0;
	b[0][0] = 1;
}
```

- 地址传递：修改本身 note：只有在获取地址的情况下对值进行操作才能真正修改变量

  ```C++
  void change(int* a,int* b){//错误例子，这里是是获取指针对指针修改，仍然是值传递，不修改原来的a、b
          int* temp = a;
          a = b;
          b = temp;
  }
  ```

- 引用：含义是给变量起了一个别名，对引用变量的操作就是对原变量的操作。引用&和取地址符&不同。

  ```C++
  void change(int &x){
      x = 1;
  }
  ```

  note:

  引用VS指针：

  ​	引用本身存放的是引用对象的地址，通俗点理解就是引用就是通过指针来实现的，所以，应用所占的内存大小就是指针的大小。 引用int &b = x;b的地址我们没法通过&b获得，因为编译器会将&b解释为：&(*b) =&x ,所以&b将得到&x。也验证了对所有的b的操作，和对x的操作等同。

  ​	然而引用和指针并非相同。

  note：指针的引用int* &p,可以用这种方式作为参数，在函数中修改原指针的值。注意原指针指向的值不变。

  ```C++
  #include<cstdio>
  
  void swap(int* &p1,int* &p2){
  	int* temp = p1;
  	p1 = p2;
  	p2 = temp;
  } 
  
  int main(){
  	int a = 1,b = 2;
  	int* p1 = &a,*p2 = &b;
  	swap(p1,p2);
  	printf("%d,%d\n",*p1,*p2);// 2,1
  	printf("%d,%d",a,b);//1,2 只是指针的值变了
  	return 0;
  }
  ```

  **note:引用是变量的别名，只能针对变量。&a,&b是a,b的地址，是常量。不可以swap(&a,&b),必须用变量p1,p2存储。**

  同理，char s[20] = “abc";不可以直接change(s)(void change(char* &s1){}),而且也没必要

  ```C++
  #include<cstdio>
  void change(char* s){
  	s[0] = 'Y';
  } 
  int main(){
  	char s[20] = "Hello";
  	change(s);
  	printf("%s",s); 
  	return 0;
  }
  ```

### (8)指针(11.25)

指针变量：数据类型* p;

​	note: `int* p1,*p2,p3;//p1,p2是基类型为int的指针，p3是整型`

​				指针定义的时候最好赋值，即使是NULL(空指针)，否则容易出错

```
int* p = &a;//&取地址符号
*p = 122;

char* s = "Hello";
printf("%d,%s",*p,s);
```

指针可以自加、自减；a+i十几等于&a[i]

指针有减法

​	note:结果以基类型为单位 如`int* p1=a,*p2=&a[5];//p2-p1=5`

### (9)结构体struct(11.26)

- 定义（+初始化way1）：

```C++
struct Name{
	int id;
	char name[20];
	//...
}A,B[2]= {1,"li",2,"liu"},*p;//可以这样初始化
```

- 初始化way2： Name a;

- 访问结构体内的元素：A.id / (*p).id / p->id

- 构造函数：直接在结构体中；不用写返回类型；函数名和结构体相同即可

  - 如果没有写则默认生成一个隐藏的Name(){},此时不需要赋值；
  - 如果手动写

  ```C++
  Name(int _id...){
  	id = _id;
  }
  ```

  or

  `Name(int _id...):id(_id)...{}//单行解决`

  这种情况定义的时候就要初始化了

  - 如果两种情况都要，或需要多种初始化情况，则各情况构造函数都要写上

  例：

  ```C++
  struct Pnt{
  	int x,y;
  	Pnt(){}
  	Pnt(int _x,int _y):x(_x),y(_y){}
  }pt[10];
  int main(){
  	int num = 0;
  	for(int i = 0;i < 3;i++){
  		for(int j = 0;j < 3;j++){
  		pt[num++] = Pnt(i,j);
  		}
  	}
      return 0;
  }
  ```

## 3.数据结构

### (1)数组（11.25）

- #### A (定长/普通)数组：数据类型 数组名[数组大小]


​	note：初始化未指定赋值时一般初值0

#### 	#note12：定义较大数组时（约10^6级及以上）需要定义在主函数外面（静态存储区），原因是系统栈中允许申请的空间比较小

#### 	#note13：对数组中每个元素赋相同的值/重置数组（多次循环的时候勿忘重置）：memset（仅char/int：0，-1/bool：false时使用，fast）&fill（其他值均用fill否则易出错）：

​	**memset**：按字节填充（0：00000000,-1:11111111）赋其它值易出错

​	用法：

```C++
#include<cstring>//or #include<string.h>
memset(数组名,值,sizeof(数组名))//无论几维数组均可
```

​	**fill：**可以按字符单元赋各种值

用法：

```c++
#include<algorithm>
fill(a,a+5,1);//一维

int dist[N][N];
fill(dist[0],dist[0]+N*N，INF);//二维

fill(v.begin(),v.end(),2);//vector
```

​	**note：fill也可以用于STL vector**

- #### B 字符数组


​	字符数组有两种初始化：

```C++
char str[10]="Hello!"//way1
char str[10]={'H','e','l','l','o','!'};//way2
```

​	**note:第一种方法只能赋值时用，其它位置不可以！**

​	字符数组可以用printf(“%s”，str);输出

​	字符数组的长度一定要比实际字符串长>=1,'\0'

​	字符数组输入输出：见输入输出小结

- #### B’ 字符数组相关函数（cstring库函数)


```c++
#include<cstring>//#include<string.h>
```

​	note：这些都是针对字符数组的,不是string类！

- strlen(str) ：return int。长度，不包括'\0'。string里length也不包括‘\0'

- strcmp(str1,str2):return 负数（str1<str2)，0，整数。不同编译器不同,不一定是1/-1

- strcpy(str1,str2):将str2包括'\0'复制给str1 

  **note:void 无返回值；是整个赋值，而不是覆盖，即使str1长度大于str2也没有剩余；且字符数组不能用str1=str2复制**

- strcat(str1,str2):**return void ，str1变为str1+str2**

- sscanf&sprintf:见1.(5)输入输出小结



## 4.做题总结注意事项

#### note14：所有问题一定在纸上拿一个实例推一遍，并考虑极限情况！！！

#### note15：极限情况：如最大子序列和，都是负数时是否可以取空串0

#### note16：序列问题是否要求连续！一般子序列可以不连续，子串必须连续

#### note17：路径/方案策略问题/可以用一个前/后继数组pre/choice保存path（每一步的选择），最后递归或者迭代即可获取方案。多个最优路径也可用vector

#### note18：图问题考虑是否连通

#### note19：图问题为了防止无法停止循环，可以增加vis[]保存遍历过的点

#### note20：数组长度不定长的时候最好在主函数外定义好足够大的区域，而不用动态分配，慢；

#### note21：不定长多维数组可以存为一维数组+记录各维度长度。`stu[][]` `stu[]`认真选择

#### note22：取中间值用mid = l + （l - r) /2 //不写成(l+r)/2

原因1：l r是指针的时候必须l + （l - r) /2

原因2：（l+r)/2容易溢出；

原因3：负数

> 当l=-200，r=-99时
> (l+r)/2=-149
> l+(r-l)/2 =-150

#### note23：快速排序/二分查找明确四点！right是否取得到+边界条件!!</>/<=/>=+mid取值（取整方向）+right/left更新(mid归属,+-1）应该谨慎！！认真想好

如果不是查找，例如merge则mid在哪都可以；但是如果是查找则要考虑right,left更新

```C++
//No1.[l，r)?[l,r]?
//No2.mid = l + (l - r)/2
//No3. left =  mid + 1/right = mid - 1

if(test(mid)) l=mid;
else r=mid-1;  
//如果用 mid=(l+r)/2  会出现问题！！！ 取l=3,r=4,test(3)&!test(4)会发现程序死循环！！!
//原因：左闭右开区间，还向下取整；在3处卡住不再更新
//方法：得向上取整，得用 mid=l+(r-l+1)/2;

if(test(mid)) r=mid;
else l=mid+1;    
//如果用 mid=l+(r-l+1)/2;  会出现问题！！！ 取l=3,r=4,!test(3)&test(4)会发现程序死循环！！!
//原因：左开右闭区间，还向上取整；在4处卡住不再更新
//方法：得向下取整，得用 mid=(r+l)/2;
```

#### note24:++i好像更常用一点，返回左值i;i++是加了i又返回i的值

#### note25：stoi/atoi C++string转int/float；反之to_string

#### note26：istringstream输入

#### note27:emplace代替insert，push_back,push_front/push提高速度(适用于各种STL容器)

容器中插入的元素永远都不是元素本身，而是元素的一份copy。emplace其实就是调用了拷贝构造函数，在容器创建元素时，就直接根据需要插入的元素进行了构造。而insert,push_back等，先是构造了元素，在调用了重载运算符函数，对函数进行了赋值。所以比较耗时。故推荐使用emplace组的函数进行插入。注意：在map表中，emplace是有些许的不同，它是返回了一个pair，第二个值是bool值，表示插入的是否成功(map键是唯一的,所以当有相同的key插入时，是会失败的)
emplace族的三个函数：emplace_front(),emplace_back(),emplace()

#### note28：有时候不要把问题想得特别大，保留所需的最精简/局部信息信息即可。例如218、239题可以使用两个数据结构，一个全部数据（还可以利用原有顺序信息），还有一个数据结构用于当前相关数据的排序/记录。具体使用什么数据结构根据需求再定，然后可以巧妙设计数据结构优化。PSleetcode502,数量级很大的时候不必全部排序，只需要局部排序即可（有序vector+priority_queue存局部）

这个思想简单题也能用上，无论什么问题都是最精简比较好。解完一定要思考是否优化到最大程度leetcode447

#### note29：类似note28，复杂问题可以先合理分类如题218:左右交点，然后聚焦到怎么得出一个解（如移除top后的右交点），然后巧妙利用迭代简化问题。

#### steps！！！note30：所有问题要先！花时间！整体分析转化问题（把握问题本质和特定，转化问题，如题332找入度=出度+1的点然后逆序即可/题310只需要考虑indegree操作完全不用考虑原图上的操作）,然后细化局部求解+仔细分析需求选取数据结构（遍历+删边，没有出边即加到res vector里/需要排序+映射+有重复值->multimap，而不是用多个vector扑腾），最后用笔推一下特殊情况和边界条件+多测试！。一定要想清楚再动手！！各个变量定好意义和思路之后一定不要轻易变化！

#### 找到隐含条件，找到抓手！尽可能

整体分析**转化**问题+局部求解细化过程+用笔推特殊和边界

#### note31：可以用stack设计单调栈！/priority_queue！/+哨兵数组！，有序存储当前未解决问题（503，84可以转化得到隐藏信息，例如两侧均大于当前的柱高的位序）！！！

#### note32：利用数组索引储存并行信息，如该值出现过则该处值为0/负数。想尽各种方法多存储信息：448，287

#### note：用a&1判奇偶much faster

#### note33：可用partial_sum,lower_bound，accumulate等函数，不仅方便而且快！！！

#### note34：对于O(n)要求的题目，可以考虑多次迭代解决，不用非要一次遍历解决

#### note35：排列组合类问题使用定长数组+cnt+-比不断pop/push快很多

#### note:if(num)不能区分1和-1

#### note:时刻估计是否数组越界！

#### note:起终点都固定时找最短路径可以两边同时bfs比单边bfs快！

#### note36:要多次利用的值注意不要被++/reverse/insert等影响

#### note37:审题子序列、子串等问题一定要判断一下是否要求连续。leetcode中子序列（subsequence）不必连续，子数组（subarray）或子字符串（substring）必须连续。、

#### note38：对于有复杂限制的问题，拆分成不同方向/小限制的组合！！！leetcode135，542

#### note39：几何题可以多画画图，找到转换条件公式！：221

#### note40：熟练dp和记搜两种写法，dp快一点

#### note41：链表题快慢指针技巧！fast/slow+left/right

#### note42:混乱的时候不要硬堵，总有更简便优雅的方法 437。树用递归much easier

#### note43：处理子串/子序列的时候不用复制，可以构造辅函数传原数组引用+index范围原地处理much faster：leetcode105

#### note44:TreeNode/ListNode等记录prev用指针类型标记/用node->next->next，省着二次遍历

#### note45：函数返回值不用每次都代表相同的含义，可以有特殊情况，只要最终得到符合题意的结果即可（leetcode236，函数对应的是pq两个节点的最小共同父节点，但是对于一个节点的父节点也有返回值；根据左右子树的返回值情况相当于做异或返回总结果。

#### note46：升序降序一定弄清楚！！！eg priority_queue降序！

#### note47：利用list+unordered_map实现O（1）查找和删除和插入：leetcpde432 146

#### note48：cmp函数一定要传引用不要传值！！！！差距很大！！！或是vector<vector<>> 直接使用cmp即可不用自定义！！！见leetcode5864

#### note49：注意链表增删问题特殊考虑移动head的极端情况！必要时+dummy

#### note50：找特定要求排列组合时可以顺序：列出所有可能筛选正向思考/倒序：利用前缀树等构建，计算数量。构建leetcode600/筛选leetcode5870

#### note51:观察数据量，敢于暴力遍历leetcode5869

#### note52:常用中间量要会用变量存储不要一次一次算，much faster。leetcode54

#### note53：最短路径类问题想到广搜，就别用dfs硬抗了。所有路径dfs回溯可，最短用bfs。拿到题先思考，不要直接硬写。leetcode127

#### note54：分情况判断的题目如果判断是否是某特殊情况很exhausting，不单独写，可以把它放到其它情况解法种一步一步筛出来：leetcode201

#### note55：同样思路int[]比vector性能好很多：但前提是操作简单，长度和初始化固定。leetcode36性能提升好多！

#### note56：删改很多的时候不用vector，而是用list！性能好很多！leetcode355

#### note57:动态规划等考虑倍数更新，如leetcode650

#### note58:二分法不要总想着加复杂的判断终止条件，应该完全使用while（left,right)判断。理清思路再写其实并不复杂。忌一顿乱写leetcode275

#### note59:sum和各个位数和之间关系：各位数和%9==sum%9见leetcode258

#### note60:有事捋清思路，可以化复杂条件筛选为顺序一步一步走然后更新得到结果leetcode11

#### note61构造dp数组的时候多重循环遍历顺序很重要！！！，用笔画一画体会一下不同含义 ：leetcode377！！！

#### note62：图问题要想到转换为顶点问题：入度出度、重复数等leetcode391

#### note63:通过unordered_map<TreeNode*,int> 实现树的动态规划.leetcode337

#### note64：遇到有具体数字阈值的时候一定要想到二分搜索优化，需要时记得可以合理利用stl-api二分搜索（set+lower_bound），leetcode315+363

#### note65：暴力一部分+优化(降维)，leetcode363

#### note66:一级/二级排序顺序很重要，尤其是有对比的时候设置好可以事半功倍。且不一定一个顺序，见leetcode354

#### note67：字符串匹配时善用二维动态规划：dp[i][j] leetcode44

对于可变长匹配，认真思考状态转移方程：

`situation p[j] == '*' :dp[i][j] = dp[i][j-1]||dp[i-1][j]`这里不用列出所有i-1,i-2....这样递归即可！！！

#### note68：dfs时候无论tmp还是vector<res>传引用真的快好多！

#### note69：使用vector实现单调栈！！！top使用index+有好处->简单，且可查看下一个值 

#### note70：不要要求一下子构造出最优解，复杂问题可以考虑从一个维度遍历：如leetcode321拼接最大数，可以遍历两个数组最大子序列长度i+j == k。多算一点中间结果出来反而算法更经济！

#### note71：寻找符合要求的子段i-j的情况，可以用二分+归并降低问题规模同时控制i< j！！！！！leetcode327

#### note72：线段树用法--统计一段区间内的和/平均值+build，insert，count。参考桶排序的思路，可以遍历y结果/遍历x...区间内节点可变：可以实现O（logn)查询和插入，可以保存l，r，sum。leetcode327

###### https://leetcode-cn.com/problems/count-of-range-sum/solution/qu-jian-he-de-ge-shu-by-leetcode-solution/

#### note73：离散化！！！leetcode327

#### note74：平衡状态问题可以逆向思考--先假设状态（学会用数据结构保存必要状态，哪怕多用一点空间），然后明确变化关系和边界条件不断动态改变直到平衡（如：可以每次将改变点加入q，再改变受其影响的点知道不再变化。leetcode407！

#### note75：数学问题分情况写一写找规律！，利用逻辑性手动化简统计一下可以找到数学问题规律：eg想到将数字各位拆开分别统计 leetcode233 leetcode400

#### note76：记搜：unordered_map<string,int> 将状态转化为string表示然后记录答案

#### note77：数字问题不用维护很大记录，提取转换为只维护一些统计量step、start等即可，降低开销leetcode390