# C/C++学习

int:一般32位

用sizeof返回多少字节

char bool

size_t:用来表征内存大小，本质是一个unsigned int。表达内存，表达元素个数用的多。无符号，大于0

float 32位 ；double 64位

const float 可以用来替换宏定义。



cout.precision(n)，保留n位有效数字。

cout.width(len)。总共宽度是len。

cout.fill('+') 设置填充字符，搭配cout.width使用。

还用用iomanip的库的，就不细学了，要用再学。

### 8.13

- **if**

```c++
bool IsPostive = true;
int factor;
factor = IsPositive? 1 : -1; // 三目运算符

// 或者可以写
factor = (IsPositive*2) - 1; // 这么写不用跳转
```

if括号内的条件都会转化为bool

- **while**

while / do while -> do while 会先做一次，再开始判断

break直接跳出循环，continue跳出当前次数的循环

- **for**

for(i = 0; i < 10 ; i++){

int sum += i;

}

for的死循环：for( ; ; )

while的死循环: while(true)

#### 8.17

- **switch**

![image-20250817154214479](C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20250817154214479.png)!(C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20250817154214607.png)

#### 8.18

- 数组
  - 初始化：int num_array[5] = {0，1，2，3，4}
  - 数组长度可以变化。变长数组：int num_array[len]。变长数组最好不要直接初始化。
  - 未知长度数组 float values[]
  - **数组的名字其实只是一个指针，指向数组存放的首地址**，所以不能直接array1 = array2。所以想要复制数组，一个方法是写循环，逐个让其相等。第二个方法是用内存拷贝。
  - 在c/cpp中数组元素的读写是不检查是否越界的。所以要注意索引长度。尤其是写，可能会把其他变量修改了。


![image-20250818104748954](C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20250818104748954.png)

**写二维数组传参时，一定要注明列数，要不然内存存储的时候不知道一行有多少个**,要不然找不到第二行从哪里开始。；

**const arrays**:常量，数组中元素不可以再修改。可以用在只需要读数组元素的时候，再函数调用的时候加入const，这样就防止数组元素被误写，被不小心修改。

- 字符串
  - char rabbit[16] = {'P','e','t','e','r'};
  - char good[5] = {'g','o','o','d','\0'};
  - 字符串数组最好要以\0为结尾。
  - 常量字符串：
  - char name1[] = "NEU"; 这个数组长度是5。
  - 字符串拷贝：char* strncopy(char *dest, const char *src,size_t count)。count代表最多可以复制的位数。
  - 字符串连接：char *strcat()
  - 字符串比较：char *strcmp()返回编码值做差


字符串类（因为正常的字符串拷贝，连接非常危险，容易出错，所以用std::string）

![image-20250818190601356](C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20250818190601356.png)

- **结构体**
  - 定义struct Student{};里面有不同的成员。
  - 然后应用时：struct Student stu; **C语言要写struct，c++不用**
  - 引用成员变量：stu.name
  - 一般放在函数外定义（包括main函数）。


```c++
struct Student{
	char name[4];
	int born;
	bool male;
};

struct Student stu;
stu.born = 2000;
strcpy(stu.name, "Tom");
stu.male = true;

// 也可以以下形式
struct Student stu = {"tom", 2000, true};

// 也可以定义一个数组
struct Student students[100];
students[50].born = 2002;
```

**联合体union**

所有成员有相同地址。共享同一块内存空间。

**联合体这块有一个小笔记，写在linux lab4的exercise3里面**

简单来说就是所有成员共享地址，每个成员变量的赋值都会影响其他成员变量，只不过不同成员变量因为类型不同，读取的数据字节数不同。

**枚举enum**

enum color {WHITE, BLACK,RED,GREEN,NUM_COLORS}

enum color pen_color = RED;

pen_color = color(3)

代码clone下来了，要着重看一看enum部分的代码。

enum在lab4里的应用也很奇怪，如果以后有需要应用的话再看一看。

- ### **指针**

指针本质上是一个unsigned int，即指针变量是一个地址。

**指针就是一个存放地址的特殊变量**

一个指针`int * p = &num;`,打印p则打印结果为地址，打印(*p)则是打印出p指向的变量。

```c++
int a;
int num = 0;
int * p = &num;

//可以对指针进行偏移
p[1] = 2; //即指针所指的地址的下四个字节的地址指向的元素，赋值为2
*(p+1) = 2； 同理

// 指针也可以是结构体类型
student stu = {"Yu",2001,true};
struct student *p = &stu;
p-> born = 2002;
(*p).born = 2002; //上面两者同理
```

利用指针修改结构体的变量。

- 指针的指针：int ** pp = &p;

- 常数指针 const int *p1 = &num ； 则不能再通过指针修改num。效果：指针指向的内容不会在函数里被修改，防止误操作。

- **pointers-and-arrays**

  - 1.数组名本身可以看作一个地址

    printf("&students = %p\n", &students)

    printf("students = %p\n",  students)

    printf("&students[0] = %p\n",&students[0])

  - Student * p = students;

    p[0] = 2001;//可以这样对students来赋值，这里students是数组名。

  - 指针偏移

  **动态内存管理**

  堆和栈是两个不同的区域，一般从堆来申请地址。（栈地址越申请越小，堆越申请越大）。正常的变量声明时，地址从栈stack中给出。
  
  **C语言申请地址**：void* malloc(size_t size)，这里void根据想要申请的类型可以变化。int * p1 = (int*) malloc(4);
  
  申请完内存一定要**释放**（free）。同时如果在一个函数内，在函数return 之前申请的地址没有释放，那么就内存泄露了。
  
  所以在哪里申请就在哪里释放。
  
  **c++申请地址**：`int * p1 = new int;`申请一段内存，赋给指针p1。
  
  `int * p1 = new int(5)`：申请一个整数，初始化为5，地址赋给p1。
  
  也可以用{},用的更多，int * p1 = new int{5}；
  
  对于结构体：Student *ps1 = new Student{};类也是类似的。
  
  对于数组：int *pa1 = new int[16]{1,2,3}
  
  释放：delete p1; delete ps1;
  
  对于数组释放，尽量要在前面加一个[]，即delete [] pa1;delete []psa1;
  
  
  
  
  
  ![image-20260122153331641](C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20260122153331641.png)
  
  偏移的不是一个字节，而是按元素偏移，比如说int类型，则是一下偏移4个字节。这里偏移用p[2]也可以（类似数组，更体现了数组名也算是一种指针）。

### 函数

 ①注意：需要对函数参数输入的合法性进行判断(robust)

② 函数应用前要先进行声明。

- **pass by value**

  - 只是**参数拷贝**，不影响函数外的参数。

  ```c++
  int foo(int x)
  {
  	//x 只是拷贝。
  	x+=10;
  	return x;
  }
  
  int main()
  {
  	int num1 = 20;
  	int num2 = foo(num1);
  }
  //这里计算后num2为30，但num1仍为20。
  ```

  - pass by value: pointer其实也是一样的道理，参数拷贝

  指针本身（地址）没变，是一份拷贝，但是函数内修改了指针指向的内容，所以内容改变了。 
  
  ```c++
  int foo(int * p)
  {
  	(*p) += 10;
  	return *p;
  }
  int main()
  {
  	int num1 = 20;
  	int * p = &num1;
  	int num2 = foo(p);
  	return 0;
  }
  ```
  
  这里main函数的p复制了Num1的地址，送入函数。但其地址指向的内容做了修改。将* p拷贝，传给函数内的局部变量* p。
  
  指针变量要注意检查，不能是空指针。
  
  - pass by value:structure
  
  在函数内部修改了结构体变量，没事，因为在函数内部操作后，函数拷贝的局部变量会被销毁。
  
  指针是特殊的，因为拷贝的是指针地址。修改结构体内部指针变量（地址）没事，但是如果你在函数内部修改了指针指向的内容，那么其内容是会发生变化的。（如下图）
  
  

![image-20250823162445322](C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20250823162445322.png)

函数的参数调用本质上是复制copy，把外面定义的matA复制给函数里的mat，进行操作，函数操作后的matA是不变的。

pass by value的弊端：如果复制的变量占1kb内存，或者更大，每次复制的话非常占内存空间。

- **references引用（C++特有概念）**

  - 实质：一个变量的别名 `int & num_ref=num;`既可以通过num来访问此变量，也可以通过num_ref来访问。
  - 再对num_ref赋值时，比如num_ref=10,num也会发生变化。
  - structure references：`Matrix & matA_ref = matA;`这里结构体matrix和matrix matA都是之前定义好的。
  - pointer和references的不同之处：指针是存放地址，指向matA变量首地址，引用则是直接是matA的别名。引用更安全一点。
  - references声明的时候一定要直接初始化。
  - **解决pass by value拷贝占内存可能过大问题**：用references

  ```c++
  struct Matrix
  {
  	int rows;
  	int cols;
  	float * pData;
  };
  
  float matrix_max(struct Matrix & mat)
  {
      float max = FLT_MIN;
      for(int r = 0; r< mat.rows; r++)
      {
      	for(int c = 0; c<mat.cols; c++)
          {
              float val = mat.pData[r*mat.cols + c];
              if(val > max)
              {
                  max = val;
              }
          }
  	}
      return max;
  }
  ```

  - **但要注意，用了引用之后，相当于把函数外部的全局变量也修改了**！如果想要不改，那么加上const，即`float matrix_max(const struct Matrix & mat)`这样mat就不会被修改。

- **return**

  - 根据函数返回值类型进行return。
  - 可以返回基本数据类型，也可以返回结构体，类这种类型。
  - 返回时要注意一系列指针，引用操作，来实现开发效率的增加。有些函数可以以bool类型作为返回值，返回true和false来判断是否成功进行函数内操作。

- **inline 函数**

防止多次调用，**相当于直接把函数粘贴到主函数里**，用更长的指令代码换取更快的时间，一般Inline函数都比较简单。

`inline float max_function(float a, float b)`

为什么不用宏？ 宏比较危险容易出错。会替换时反复进行操作，详见week06 inline.cpp。同时运算级要加括号，需要更严谨一些。

宏很容易出错，c++中不太用宏。

- **arguments**（c++中特有的一些特性）

  - float norm(float x, float y, float z = 0),默认参数要在尾部定义。（z已经声明后，如果再声明就必须从y开始。）
  - defualt arguments（默认参数不能重定义）。
  - 在参数列表非常多非常长的时候，可以更方便给参数。

- **函数重载(overloading)->cpp特性**

  - ```c++
    int sum(int x, int y)
    {
        cout << "sum(int, int) is called" << endl;
        return x + y;
    }
    float sum(float x, float y)
    {
        cout << "sum(float, float) is called" << endl;
        return x + y;
    }
    double sum(double x, double y)
    {
        cout << "sum(double, double) is called" << endl;
        return x + y;
    }
    ```

  - 可以对**同一函数名**设置**不同类型参数**

  - **如果只是函数的返回值不同，是不可以被重载的！**

- **函数模板(function templates)**

  - 对于以上的sum函数，可以用一下模板类写：

  - ```c++
    template<typename T>
    T sum(T x,T y)
    {
    	cout<<"The input type is "<<typeid(T).name()<<endl;
    	return x+y;
    }
    ```

  - 但是这时候编译器不知道什么类型，也不知道怎么做加法，所以需要进行**实例化**

  - `template double sum<double>(double,double); //对模板中的加法实例化`。

  - 如果再声明template char sum<>(char,char)，template int sum(int,int)，就是实例化三个函数。

  - ```c++
    #include <iostream>
    #include <typeinfo>
    using namespace std;
    
    template<typename T>
    T sum(T x, T y)
    {
        cout << "The input type is " << typeid(T).name() << endl;
        return x +
         y;
    }
    // Explicitly instantiate
    template double sum<double>(double, double);
    
    int main()
    {
        auto val = sum(4.1, 5.2);
        cout << val << endl;
        return 0;
    }
    
    ```

  - 还会隐式实例化。

  - 函数重载特例化：注意模板template后要加一个<>

  - ```c++
    // Specialization for Point + Point operation
    // 特例
    template<>
    Point sum<Point>(Point pt1, Point pt2)
    {
        cout << "The input type is " << typeid(pt1).name() << endl;
        Point pt;
        pt.x = pt1.x + pt2.x;
        pt.y = pt1.y + pt2.y;
        return pt;
    }
    ```

  **做lab的学习：用函数模板的时候，适合把定义直接放在hpp文件中，最好不把定义写在cpp中，声明写在hpp中，这样麻烦。直接写在hpp中就可以。**->详见lab7 exercise1-2

  如果是正常的函数重载，不用模板，那就一切照旧。

- **函数指针/引用**

  - 先决条件：满足函数返回值和函数参数类型相同。指针指向函数。

  - ```c++
    float norm_l1(float x, float y); //declaration
    float norm_l2(float x, float y); //declaration
    float (*norm_ptr)(float x, float y); //norm_ptr is a function pointer
    
    int main()
    {
        norm_ptr = norm_l1; //Pointer norm_ptr is pointing to norm_l1
        cout << "L1 norm of (-3, 4) = " << norm_ptr(-3.0f, 4.0f) << endl;
    
        norm_ptr = &norm_l2; //Pointer norm_ptr is pointing to norm_l2
        cout << "L2 norm of (-3, 4) = " << (*norm_ptr)(-3.0f, 4.0f) << endl;
        return 0;
    }
    ```

  - 上面两种指针赋值都可以。

  - 也可以有函数引用，**函数引用必须在初始化时直接赋值**，使用略少。
  
- **简单讲解递归函数(recursive)**

  - 自己调用自己。

  - 例子：

  - ```c++
    #include <iostream>
    using namespace std;
    
    void div2(double val);
    
    int main()
    {
        div2(1024.); // call the recursive function
        return 0;
    }
    
    void div2(double val)
    {
    
        cout << "Entering val = " << val << endl;
        if (val > 1.0)
            div2( val / 2); // function calls itself
        else
            cout << "--------------------------" << endl;
        
        cout << "Leaving  val = " << val << endl;
    }
    
    ```

  - 以上程序的输出为：

  - ```
    Entering val = 1024
    Entering val = 512
    Entering val = 256
    Entering val = 128
    Entering val = 64
    Entering val = 32
    Entering val = 16
    Entering val = 8
    Entering val = 4
    Entering val = 2
    Entering val = 1
    --------------------------
    Leaving  val = 1
    Leaving  val = 2
    Leaving  val = 4
    Leaving  val = 8
    Leaving  val = 16
    Leaving  val = 32
    Leaving  val = 64
    Leaving  val = 128
    Leaving  val = 256
    Leaving  val = 512
    Leaving  val = 1024
    ```

  - 我的理解是：一开始1024:满足，然后再逐步递归，分别enter，直到1，不满足了，打印横线。此时，每个递归函数都没有执行完成，再依次退出，从val为1时退出，一直退到1024.

  - 如果无穷递归，则栈每次都会消耗，没有回收，stack会爆掉。

  - 优点：代码量小，适合树数据结构。缺点：可能有stack问题，需要逻辑严密，较难执行和debug。


### 代码优化

- 代码优化的几个tips
  - 1.合适算法。2.直观简洁。3.优化内存 4.避免内存拷贝 5.循环中尽量不要print/cout(影响效率)6.查表法table lookup
  - 不同cpu有不同加速代码的指令/指令集。**SIMD,OpenMp**.

- opencv中有一个**ROI**机制：region of interest
  - ![image-20260221124111705](C:\Users\86134\AppData\Roaming\Typora\typora-user-images\image-20260221124111705.png)
  - 对于Mat C，截取一个30*28的矩阵，这里的step是指第一行第一个元素和第二行第一个元素之间差了100号（就是大矩阵中一行的个数或者大矩阵的列数）

函数默认参数要从尾部开始设置。

- **类class**

类变量一般private(默认private)

类函数可以在内部定义，也可以在外部定义，简单实现的函数适合放内部，复杂的适合放外部。

外部定义的话要在内部声明，然后外部定义

```
void Student :: setGender(bool isMale)
{
	male = isMale;
}
// 外部定义要类名：：函数名
```

C++项目管理，类的声明可以放在头文件.hpp文件里，函数定义可以放在.cpp文件里

- 构造函数与析构函数

1. 构造函数
	如果没定义构造函数，系统会自动生成一个新的。
	在public里面，函数名字和类名相同，无返回值，可overload
	还可以通过new来申请。> Student * zhou = new Student("zhou", 1991, false);
	zhou -> printinfo
2. 析构函数 ~Student()
	析构函数不能overload
	
	功能：释放掉内存等等，总而言之就是删除构造函数所占用的一些东西。
	
	如果这样申请的：Student * class1 = new Student[3]{
	{"a",2001,true}, {"B",2002,true},{"c",2002,false}
	};
	
	只有delete [] class1才会调用三个对象的析构函数。
	总结：new的是一个数组，那么delete的时候要用delete[]

- this指针
  可以指向当前类变量的成员变量/成员函数。
  this->born = born；前面是成员变量，后面是函数参数。

- const and static-members
  const int BMI = 24; 这个就是成员变量不能修改。
  
  ```c++
  class ConstMember
  {
      private:
          const int m_a;
      public:
          //constructor
          ConstMember(int a):m_a(a){} //const变量必须在创建的那一刻就被初始化。等价于m_a = a,构造函数里面是空的
  
  ```
  
  const变量在创建的时候就要初始化，必须通过m_a(a)这种在构造函数中初始化。相当于m_a = a。
  
  int getBorn() const
  {
  ...
  }
  这个const代表了函数内不能修改成员变量。
  
- static变量和static函数：这里比较难。
  - 在所有对象中唯一，有5个对象，在对象中也只有这一个static member
  - 静态变量属于类，与对象无关。
  - **静态函数中不可以修改非静态数据**。

static变量在所有类变量对象中唯一，

lab9学习心得：一般可能现有hpp，再写cpp。hpp是接口设计环节，相当于先设计架构，然后再在cpp中具体实现。



### 运算符重载

- **运算符重载**

可以对+等运算符重载，以实现比如说类与类之间成员变量的相加减。

operator+(int m)

```c++
MyTime operator+(const MyTime & t) const
    {
        MyTime sum;
        sum.minutes = this->minutes + t.minutes;
        sum.hours = this->hours + t.hours;

        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        
        return sum;
    }
    MyTime & operator+=(const MyTime & t) 
    {
        this->minutes += t.minutes;
        this->hours += t.hours;

        this->hours +=  this->minutes / 60;
        this->minutes %= 60;
        
        return *this;
    }

    MyTime operator+(int m) const
    {
        MyTime sum;
        sum.minutes = this->minutes + m;
        sum.hours = this->hours;
        sum.hours +=  sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
```

但是如果是20+t1，那就不行了！所以要用到下面的知识点：

- 友元函数 friend functions

朋友函数：①在类里面声明，②有访问private变量的能力，③但是不是类的成员。  

如果在类里面定义，那就直接加friend：

```c++
class MyTime
{
	//...
	public:
		friend Mytime operator+(int m, const MyTime & t)
		{
			return t+m;
		}
}
```

如果是只在类内部声明，在类外部定义，要注意：不加**类名：：**

```c++
class MyTime
{
	//...
	public:
		friend Mytime operator+(int m, const MyTime & t)
	
}
Mytime operator+(int m, const MyTime &t)
// 而不是：Mytime Mytime::operator+(int m, const MyTime &t)
{
	return t+m;
}
```

因为友元函数不是成员。

对<<重载，要通过friend function。

在进行这个overload的时候，一定要注意return os，即返回值类型是std::ostream &，这个变量类型。因为返回这个相当于返回了一个cout，可以进行链式传播。即**cout<<t1**<<endl;可以成立，前面重载的cout<<t1可以等价于一个cout。

- user-defined Type Conversion自定义类型间的类型转换（也可以视为=的重载）
  - 也是通过operator 重载。比如说把MyTime类型转换为int型，则有
  - ` operator int() const`这是可以隐式转换。
  - 如果这样写：` explicit operation float() const`，加入explicit，这代表必须进行显式转换。推荐加上explicit。
  - 这里等于号=的重载还有一系列需要注意的地方。比如说MyTime类和int类的相互转化。
  - **这里还挺复杂挺难的，需要做Lab的时候再详细学习。**

```
MyTime t = 70; 能生效的核心是单参数构造函数的隐式类型转换，C++ 允许用这种方式完成拷贝初始化；
MyTime t(70); 是「直接初始化」，MyTime t = 70; 是「拷贝初始化」（编译器会优化为直接构造），最终效果一致；
如果想禁止隐式转换，给单参数构造函数加 explicit 关键字即可，这也是工程中更推荐的写法（避免意外的隐式转换）。
```

- ++和--的重载

  - `MyTime& operator++()`那么最后就是return this*。这个是前置的，即++m。

  - ` MyTime operator++(int)`这个原参数不要改变，所以不用reference，这个是后置的，即m++。

  - ```c++
    // prefix increment
        MyTime& operator++()
        {
            this->minutes++;
            this->hours += this->minutes / 60;
            this->minutes = this->minutes % 60;
            return *this; 
        }
     
        // postfix increment
        MyTime operator++(int)
        {
            MyTime old = *this; // keep the old value
            operator++();  // prefix increment
            return old; 
        }
    ```

  ---
  
  lab10 exercise1:第一个心得：用friend function可以实现类型间的隐式转换。



### 默认copy constructor带来的问题——硬拷贝，软拷贝解决

1. 运用默认拷贝构造函数进行初始化/赋值时， 可能会带来类的指针指向同一个地址的问题，从而引发一系列报错，内存泄漏。
2. solution1:hard copy，硬拷贝，即每一次构造时都申请一块内存。详见源码week11/example2。
3. soft copy:共享内存。主要体现在老师讲的cv::Mat类里面，有一个refcount。引用次数，是在数据前面额外占了一些存储空间。

​	归根到底，还是指针指向导致的一些问题。

4. 智能指针：只管申请，**不用管释放**。

​		① std::shared_ptr 共享的指针，如果对象没有指针指向它，这个共享指针就自动释放了。(shared_ptr是一个模板类)。智能指针不能赋给普通指针。

```c++
std::shared_ptr<Mytime> mt1(new Mytime(10)); 
std::shared_ptr<Mytime> mt2 = mt1;
```

此时二者都指向Mytime(10)。

也可以用模板函数来创建智能指针。

```c++
auto mt1 = std::make_shared<MyTime>(1,70)
```

相当于把1，70两个参数通过函数传给了MyTime类，同时mt1指向这个类。

智能指针shared_ptr有一个属性，mt1.use_count()，可以看当前指向的对象被几个指针指向。

②std::unique_ptr：此指针指向的对象不允许别人共享。

std::unique_ptr <Mytime> = mt1(new Mytime(10))

这个如果要赋值，只能用auto mt3 = std::move(mt1).这样之后mt1就没有了，相当于一个空指针了。必须要move。

智能指针本质上都是一个class。
### 派生类derived class
在已经有一个比较好的父类后，可以通过子类继承，多几个变量就可以。
```
class Base{
  public:
    int a;
    int b;
};
class Derived: public Base
{
  public:
    int c;
}
```
子类还可以继续继承。一个子类可以有好几个父类。
- 构造函数和析构函数在子类如何执行：
  - 可以在子类的构造函数中调用父类的构造函数。（详见derived.cpp）。
  ```
  Derived(int c): Base(c - 2, c - 1), c(c)
    {
        this->a += 3; //it can be changed after initialization
        cout << "Constructor Derived::Derived(" << c << ")" << endl;
    }
    ```
  - 这里就是调用了父类的构造函数，然后再在自己的构造函数中进行额外操作。
  - 子类可以和父类有相同名称的函数，也可以调用父类的函数，调用时前面要加上父类名::函数名。如Base::product。
  - 析构时先释放子类，后释放父类。

### 成员访问控制access control
`Person(const Person& other): n(other.n){}`,这个构造函数是合法的，在**类内**定义时，可以用另外一个类对象的private变量。
- protected类型：
```
protected:
  int n
```
这个n也可以在子类里用。
- 三种继承方式：public/private/protected继承
  - public继承：情况不变，Public量还是Public，private还是private
  - protected继承：父类里的Public在子类中将变成protected。
  - private:public和protected全都变成子类的private成员。
  > 这三个其实没太懂，还得ai一下。

### 虚函数virtual functions
1.举个例子：
有一个父类Person，有一个子类`class Student: public Person`，子类在父类基础上多一个变量id，都有print函数，但打印内容子类也多一个id。
然后设计一个公共函数void PrintInfo(Person & p),函数体调用p.print()。
在main函数中定义一个Student类，该类调用PrintInfo时，只会调用父类的print函数。
从逻辑上讲这样没错，但是如果要智能的调用，也能做得到------->虚函数。
```c++
class Person
{
  public:
    string name;
    Person(string n): name(n){}
    virtual void print()
    {
        cout << "Name: " << name << endl;
    }
};
```
2.涉及概念：静态/动态绑定。虚函数->动态绑定。
3.纯虚函数：无定义的一个虚函数。virtual void print()=0;
4.析构函数是虚函数，因为在delete的时候，一定不能是只将其作为父类去delete，也要把子类中的一些delete掉。

### 继承和动态内存分配 inheritance and dynamic memory allocation
如果子类中又涉及到了动态内存申请(new, hard copy, soft copy...)，那么需要额外注意，可能还需要重新定义拷贝构造函数或者重新进行运算符重载。