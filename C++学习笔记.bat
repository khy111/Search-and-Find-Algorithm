1.区别：define（宏定义）、const（常量）、static(静态变量)
2.变量名数字开不了头。
3.foalt、double型的数据区别；（有效位数，默认类型，表示方式，科学计数法）
4.\n 换行、\t水平制表符(占8位，不是字节)（eg:aaa\tbbb 对应 aaa     (前面8位)bbb）,常用于多行列对齐。
5.&&、||
6.	switch (变量)   //变量只能是整型或者字符型、或者enum数据结构，不能是区间
		{
			case 变量可能取值:
				.....;
				break;
			case 变量可能取值:
				.....;
				break;
			default:			
				break;
		}
7.if与switch的区别（精确匹配与模糊匹配）
8.while(){...}与do{...}while()的区别（while是先判断在执行，后者是先执行一次循环再判断）
9.break()的三种使用时机，与continue的区别；
10.goto A; //一般不大量使用
		...
		A:
11.二维数组行数可以省略，列数不可以。
12.防卫式定义：#ifndef TEST1_H（点用_代替，用户头文件一般不要__开头）
13.int *p=NULL;*p=100;//报错，NULL是禁止访问的。（注意：若果p是定义为指向结构体的变量，则p是一个指针，占4字节，如果想让其存储结构体的数据，则需要配合malloc\new一起使用（为其分配地址，使P指向该地址），也可接收一个结构体的指针。）
14.结构体数组定义，使用。
15.全局区存放数据包含：全局变量、静态变量（static）、常量(分：字符常量（eg:cout<<"hello world";），全局常量（const）,注意：局部常量还是放在栈区)；
16.不要返回局部变量的地址，栈区（形参、局部变量）的地址由系统释放。
17.引用在初始化后就不可以改变，因为引用的本质---指针常量（int& a=b ---> int * const a=&b）（可以有赋值操作，不可以更改引用）。
18.不要返回局部变量的指针或者引用（加static）
19.函数返回的是引用，则函数名也相当于一个引用，可以做左值。注意：此时函数不能返回NULL,因为引用不能为空。可将返回类型改为指针。
20.函数的默认参数：实参后面兄弟不能断，声明与定义二选一（避免二义性）。
21.函数的占位参数（void fun(int ,int )）
22.区别函数重载、重写条件：重载：函数名称，形参个数，形参类型，形参顺序。注意：返回值无关，同一作用域；重写：返回值，形参完全一致；不同作用域。
23.函数重载注意两种形式：1 引用的重载；2 函数默认值重载（不合法，避免二义性）。

24.面向对象的三大特性：封装、多态、继承。
25.class与struct的唯一区别：访问权限
25.属性一般放在private里面作用（保护数据）：控制读写权限；判断写数据的有效性。
26.区别复合、继承、委托：类也可以套娃（一个类包含另一个）称为复合（构造先小后大，析构先大后小）；继承（与复合相同）；委托（）。
27.#program once 作用：头文件只包含一次。
28.构造与析构函数的区别（构造：自动调用；可重载；与类同名；无返回值  析构：自动调用；无返回值；无参数；多一个~号）
29.匿名对象（临时对象）生命周期只在本行代码（构造函数的显示调用 person p=person(10); rturn person(10)）
30.拷贝构造函数的调用时机（使用对象初始化新的对象；对象以值的方式作为形参；以值的方式返回对象）
31.c++对象编程三剑客（默认构造函数、拷贝构造函数、析构函数。用户不写，编译器也会自动提供。规则：用户写了有参构造，编译器则
	不会提供默认构造；有了拷贝构造，编译器不提供其余两个）
32.深拷贝=与浅拷贝的区别（编译器提供的赋值操作就是浅拷贝，而用户自己在堆区开辟的新的内存，进行拷贝（不使用编译器的拷贝规则）。
	这就是深拷贝，经常出现在属性含有指针的情况，且使用到拷贝构造函数时（析构释放深拷贝堆区开辟的内存））
33.区别静态成员变量、静态成员函数（static）：静态成员变量：所有对象共用一份数据；类内声明，类外初始化；编译时分配内存；静态成员函数：
	只能访问静态成员变量；所有对象共用一个函数  本质没有this指针，不属于类的某个对象上。
34.空对象编译器会分配一个字节（区别多个空对象），非空则为实际非静态属性大小（不会再单独分配一个字节）。静态方法和非静态方法都不占用内存
	含有虚函数的类也会占用四个字节（本质是一个指针）
35.this指向调用对象的指针，*this指向调用对象的本体（用于return *this;（注意函数返回类型为&，防止拷贝多个对象））
36.person *p=NULL;（没有实例化对象，就没有this指针）此时对象p是可以访问public属性和方法的，但是方法里继续访问private、protected变量时，
	程序报错（解决办法：if(this==NULL)return;来防止破坏，提高程序健壮性）
37.区别常对象与常函数(const)：常对象（常对象只能调用常函数）；常函数（int add()const{...}）指针的本质：person *const this，
	常函数this指针本质:（const person *const this），所以不允许改变对象的属性。（如果允许更改，则类的属性声明时加mutable,eg:mutable int a;）
38.友元函数（类里的任何地方）目的（允许友元函数访问类的私有变量）：全局函数做友元函数、友元类（friend 类名 对象名）、
	成员函数做友元函数（friend int 类名：：函数名（））
39.区别运算符重载与函数重载：运算符重载 作用：实现自定义的数据类型运算操作；方式：分为成员函数重载、全局函数重载（形参的区别） 
										 1. +、-、*、/重载：（eg:对象+对象，编译器就不知道怎么加，需要重载+号） 
						（只能全局重载）*2. <<重载（作用输出对象）：全局函数重载（保证<<方向性）加友元函数（访问私有变量）实现，
										 ostream & operator<<(ostream& cout,类名& 别名) {... ; return cout}//注意链式编程思想
										*3. 对象++、--重载：分为前置++（返回&） 对象& operator++（）{..++..;return *this}、
																后置++（返回值） 对象 operator++（int）{对象 temp=*this;..++..;return temp}  //int 重载，防止重定义
									    *4.=重载：同问题32，当类里含有指针时，做深拷贝，方式堆区内存重复释放报错，所以需要自己重载=号，（注意：判断是否为NULL;函数返回&，链式编程思想）
										 5.>、<、<=、>=、=关系运算符重载：与加法重载类似（返回bool）
										 6.()重载：又称仿函数 ass()(100,100);//匿名函数对象

40.继承：非静态成员属性都会被继承（private也会，只是被编译器禁止访问）
41.继承：父类与子类的同名函数和同名属性的调用（子类直接调，父类加作用域 （子类对象.父类名::属性（或者方法）））。
		同名的静态成员访问（静态成员两种访问方式：1.对象调用与非静态同理。2.作用域访问： 子类::父类::被访问的静态成员）
42.多继承语法： class 子类 ：public 父类1 ，父类2 .....(不推荐使用)
43.菱形继承（A<----(B、C)<---D）会造成内存空间浪费，B、C采用虚继承（class 子类 ：virtual public 父类 ）解决这个问题（数据只保存一份）

44.区别静多态（函数重载、运算符重载、函数名复用）、动多态（派生类加虚函数实现）：静多态-编译时确定函数地址；动多态-运行时确定地址（本质）。
45.满足多态的条件：虚函数，重写父类虚方法，继承；多态的使用条件：有一个父类指针或者引用指向子类的对象（1.base *p=new child;2.通过定义一个父类函数形参来实现，（可以接受子类对象））。
 （推荐使用多态-好维护、扩展性好、可读性好，感受多态的魅力，计算器，冲泡咖啡茶叶）
46.抽象类（含有纯虚函数的类）：不能实例化对象（但是可以有自己的构造函数），子类必须重写父类虚函数（否则也无法实例化对象），本质对虚函数的简化。
47.区别纯虚析构（有申明和实现）和虚析构：1.作用：当继承的子类含有指针（堆区变量）属性时，父类的析构函数不能有效的是否子类的堆区空间，需要用父类使用纯虚析构和虚析构来解决（子类中没有堆区数据就不写）
						比如多态时，子类含有指针，在堆区开辟了内存，而调用虚构函数时，子类的析构函数就调用不到，此时就需要把父类的析构函数定义为虚析构函数。
						 2.写法：virtual ~类名（）； / virtual ~类名（）=0； 类名::~类名（）{...}//公共区域写函数体。
						 3 有纯虚函数的类也是抽象类，不能实例化对象。

48.文件操作: 分类：二进制存储（信息隐藏的作 用）；txt文本存储；
			 头文件：fstream(ofstream(写)、ifstream(读))
	   txt文本存储：写数据5步： 1：包含头文件#include<fstream>
								2:创造写文件对象 ofstream ofs；
								3：打开文件 ofs.open("文件名称"，ios::打开方式) //ios::in  (只读)、ios::out(写) 、ios::trunc(清空)、ios::binary(二进制的形式)、ios::app（文件指针定位在文件尾部）
								4.向文件写数据 ofs<<"写入的内容"<<endl;
								5.关闭文件 ofs.close();
					读数据5步： 1：包含头文件#include<fstream>
								2:创造读文件对象 ifstream ifs；
								3：打开文件 ifs.open("文件名称"，ios::打开方式) //ios::in  (只读)、ios::out(写) 、ios::trunc(清空)、ios::binary(二进制的形式)、ios::app（文件指针定位在文件尾部）
								(if(ifs.if_open()){...}//判断文件是否打开成功)
								4.读文件数据 四种方式：
														1.char buf[1024]={0}; while (ifs>>buf){};
														2.char buf[1024]={0}; while (ifs.getline(buf,sizeof(buf))){};
														3.char buf[1024]={0}; while (getline(ifs,buf)){};  //getline要包含头文件string
														//前三种都是一行一行的读，效率高
														4.char buf; while((c=ifs.get())!=EOF){}; //一个一个字符的读，效率低
								5.关闭文件 ifs.close();
		.csv文件储存格式：可以用excel打开。//注意：每个单元格的内容以","好隔开 eg: 存储格式：101,20
			
	  二进制存储的读写方式区别：1.打开文件时  ofs.open("文件名称"，ios::打开方式|ios::binary) 
								2.通过write(const char * buf,int len)\read(char * buf,int len)函数读写；
49.两个关系类避免头文件相互包含
**********泛型编程*************
50.区别：函数模板、类模板（本质：参数变量化）；
						   函数模板：templete <typename T> T add(T a,T b){...} 调用：1. add(1,2)//编译器自动推导；2. add<int>(1,2);//用户告知
						   注意：普通函数可以隐式转换，函数模板自动推导时，不可以隐式转化（报错，类型不统一），当用户告知类型时，可以隐式转换。
						   区别函数模板与普通函数的调用：1.普通函数与函数模板都存在时，优先调用普通函数（普通函数要隐式转换时，则调用模板函数）
														 2.当不想优先调用普通函数时可以利用空模板实现调用函数模板；  add<>(a,b);//指定空的模板
														 3.模板函数也可以重载；

						   类模板：templete <typename T,typename T1=int> class person{...}; 调用初始化：person<string,int> p("a",1);//类模板没有自动推导类型的调用,但可以有默认参数
							   注意：
							    1.类模板的成员函数不是一开始就创建，二是在调用的时候创建的（可以实现多态的感觉，但是需要人为指定调用的对象）
							    2.类模板做函数参数的三种形式： *1. 直接指定传入的类型： add(person<string,int>& p)//向函数add（）里面传入一个函数模板类的对象p ，此方式常用
																2. 模板参数模板化：templete<class T1,class T2> add(person<T1,T2>& p){...}
																3. 整个类模板化： templete<class T> add(T & p){...}
								3.模板类继承的时候一定要指明父类模板的类型： templete <class T,classT1> class Son:public person<T>{T1 p; ...}; //也可以直接指定具体类型。
								4.类模板成员函数类外实现时，需要添加模板参数列表： templete <typename T,typename T1=int>  //
																				 person<T,T1>::person()                 //加模板参数列表<T,T1>
																				 {...}
								5.模板类分文件编写时，会导致链接时分文件找不到（本质：就是1.中的问题）：解决：包含.hpp //约定俗成的，告诉大家这是一模板类，然后把类的定义和实现都写在这个类里面
								6.模板类的全局友元函数建议类内实现（相对简单）；

51.标准模板库;STL（standard templete libraey）组成：容器、算法、迭代器（胶合前者）、仿函数、适配器、空间配置器（管理内存） 使用优点：1.提高代码复用率 2.解决基础的算法逻辑 3.解决了堆区内存的管理
序列式容器（vector、deque、list（双向链表））
52. for(vector<int>::iterator it=v.begin();it!=v.end();it++)  //it是指向v的指针；*it是v本身（通过vector<int>::iterator得到*it的数据类型），
53.字符串的比较大小的主要作用是判断两个字符串是否相等；//compare();
55.add(const vector<int>& a){for(vector<int> const_iterator it=a.begin();;)...} //const修饰的迭代器，则函数体也应该是常量迭代器。
56.vector与deque内存扩展的本质区别：vector开辟的容量区域存满后会重新开辟新的内存-拷贝数据-释放旧的内存。而deque容器完全不一样，它有一个中控器，保存开辟空间的首地址，内存用满后继续开辟就可以了，所以没有reserve()，只有resize();  两者都有shrink_to_fit();
57.queue可以查看队尾(back())和队头（front()）的引用。
58.list容器本质：双向链表容器（所以没reserve(),迭代器也为双向迭代器，），每个存储节点独立，也因此插入和删除操作不会影响原有的迭代器；底层也不是线性、连续的存储空间，在访问元素的时候就不能使用[],at(),data()等，只能使用front\back
58.list和vector的区别：，如果需要高效的随机存取，而不在乎插入和删除的效率，使用vector;如果需要大量的插入和删除，而不关心随机存取，则应使用list。
59.区别vector与list的成员函数remove():vector.remove()返回删除元素下一位置的迭代器，并不会改变容器的大小和容量（经常需要搭配erase去掉尾巴），而list.remove（）是直接删除。容器大小也会改变。
60.不是随机访问迭代器的容积不支持全局sort()排序，因此内部就会提高排序的成员函数。（list.sort()//默认降序，想实现升序，自定义一个函数  bool mysort(int a,int b){return a>b;}  list.sort(mysort);）
61.sort()高级排序(值相等，按另外的值排序)；（list.sort()//默认降序，想实现升序，自定义一个函数  bool mysort(int a,int b){if(a=b){return ...} return a>b;}  list.sort(mysort);） //对于两个class对象排序时  可重载<>号，或者成员函数，或者全局函数实现（把函数名传入sort）。
关联式容器(map（key唯一）|multi_map（红黑树）、set、multi_set（二叉树）)
62.set、map容器erase()函数有重载，可以直接传入值和迭代器两种方式；（而序列式容器必须传入迭代器）
63.set排序分为内置数据类型和自定义数据类型：因为set容器本身就会排序，所以没有sort()方法，只有通过创建容器的第二个参数指定排序规则；区别序列式容器。
										1.内置数据类型：set<int,less/greater>p
										2.自定义数据类型（必须指定排序规则）：仿函数解决  class mysort{
																										public:
																										bool operator()(person &a,persong&b) const
																										{
																											 return  a.age>b.age
																										}};
																			set<persong,mysort()>p;	 //把自定义的仿函数（排序规则扔进去的是函数对象）,创建mysort类的临时对象； #include<functional>  less<int>()\greater<int>();
										注意：map的排序同理，只是按key值排序。
64.map重载了[],at()方法，erase()可以传入迭代器（位置、范围）和也可以是key的值。																									
65.map和set都有find()方法
66. 熟悉find(迭代器区间),find_if(区间，查找对象（谓词函数）),adjacent_find(迭代器区间)//查找相邻重复元素、count(区间、统计对象)、count_if(迭代区间，pred)//pred仿函数、sort(区间，pred)、
	merger(容器1区间，容器2区间，目标容器区间)//目标容器大小大区两个区间的和；容器1、2必须是有序的。reverse(区间)、replace(区间，旧值，新值)、replace_if(区间、pred、替换的新值)、swap(v1,v2)//全局函数的交换、
	set_inetrsection(区间1，区间2，目标容器)//求交集；目标容器要开辟空间、set_union(区间1，区间2，目标容器)//求并集 区间1、2必须是有序的，目标区间的大小必须为区间1、2的和；
	set_difference(区间1，区间2，目标容器)//求区间1独有的元素。 区间1、2必须是有序的，目标区间去1、2较大者；
67.无序关联式容器：1.同关联式容器，只是不会排序，再没有重哈希的情况下存储的元素的相对位置固定（reserve（n）提前设置桶的数量，保证不会rehash）。
				   2.在使用自定义的数据类型的时候，需要自定义hash函数和自定义比较规则（unoedered_map和unoedered_map都会去重）。
					使用函数对象类实现自定义hash函数
						class hash_fun {
						public:
						int operator()(const Person &A) const {
						return A.getAge();
						}
						};
					使用重载==或者函数对象实现自定义比较规则
					a 重载==:bool operator==(const Person &A, const Person &B) {
						return (A.getAge() == B.getAge());
						}

					b函数对象:class mycmp {
					public:
						bool operator()(const Person &A, const Person &B) const {
							return (A.getName() == B.getName()) && (A.getAge() == B.getAge());
						}
					};



