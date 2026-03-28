### project 2 向量点积
简单一个来小时做了一下这个，做的比较粗糙。

思路：分别用自定义的模板vector类和std::vector。
- 自定义模板类Myvector内：
    - 输入接口：length，vector的长度。
    - 类内动态申请内存。
    - 重新定义copy constructor，进行deep copy，避免拷贝时出现内存泄漏(robust better)
    - 运算符重载，主要是重载[]，以完成Vector赋值。
    - 定义点积算法，并通过chrono来对算法进行计时与比较。


在main程序里，通过random产生随机数，赋给vector，并进行计算。
后来又用了std::vector来计算，发现性能比自定义类慢一点点。

写了dot_product.py，python程序与c++比较，Python的numpy点积运算效率也挺高，但是c++程序如果优化编译：`g++ -O3 -march=native Myvector.cpp`。计算效率将特别高，应该是编译器调用了指令集。