# 郑鑫 18061436 c++作业



## p51

#### 2.23

不能，只能获取这个内存的内容，无法判断是否合法

#### 2.24

因为 =&i;是将i的地址赋值给前面，所以左边指针得定义为void*

## p53

#### 2.25

#####  (a)

ip为指向int类型的指针 ,i为int类型 ,r指向i

#####  (b)

i为int，指针ip为空

##### (c)

ip指向一个int，ip2为int

## p62

#### 2.25

i为const int，整型常量

j为int，k为整型常量的引用，p为指向一个整型常量的指针

j2是一个const int ，k2为指向整形常量的一个指针常量

## p81

#### 3.4

见 3.4.1.cpp   and   3.4.2.cpp

#### 3.5

见 3.5.1.cpp   and   3.5.2.cpp

## p94

#### 3.20

见  3.20.1.cpp   and  3.20.2.cpp

## p188

#### 6.10

见  6.10.cpp

## p193

#### 6.19

a：函数只有一个参数，传入两个不合法   bcd：合法 

## p210

#### 6.39

（a）错误   重构函数中一个拥有顶层const的形参无法和另一个没有顶层const的形参区分

（b）错误   重构函数不能除了返回值以外没有别的区别

（c） 正确

## p241

#### 7.16

在类的定义中对于访问说明符出现的位置和次数没有限制。在整个程序内可被访问的（如类的接口)应该定义在public说明符之后，不能被使用该类的代码访问的成员应该定义在private说明符之后。

## p249

#### 7.27

见7.27，screen

## p266

#### 7.49

(a)Sales_data &combine( Sales_data );

​	s隐式地调用Sales_data的构造函数，生成一个临时的Sales_data对象，然后传递给combine的形参。

(b)Sales_data &combine( Sales_data& );

​	编译无法通过。因为combine成员函数的形参是非常量引用，但是s自动创建的Sales_data临时对象无法传递给	combine所需的非常量引用。

​	修改为：Sales_data &combine( const Sales_data& ) 

(c)Sales_data &combine( const Sale_data& ) const;

​	编译无法通过。因为我们把combine成员函数声明成了常量成员函数，所以该函数无法修改数据成员的值。

## p272

#### 7.58

​	除了静态常量成员之外，其他静态成员不能在类的内部初始化。所以rate和vec不能在类内初始化，rate和vec的	类外定义必须给出其初始值。