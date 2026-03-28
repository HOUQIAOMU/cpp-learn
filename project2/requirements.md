# Computing the dot product of two vectors

This project involves implementing and comparing two programs that calculate the dot product of vectors - one in C and another in Java. The implementations will support various numeric data types including integers (int, short, signed char) and floating-point numbers (float, double).

## Requirements

1. Develop separate programs in C and Java that compute the dot product of two vectors.

2. Implement execution time measurement for the computation. The measured time should demonstrate a positive correlation with increasing vector lengths.
> 为该计算实现执行时间测量。所测量的时间应与不断增加的向量长度呈现正相关关系。

3. Conduct a performance comparison between the C and Java implementations. Analyze and explain any observed performance differences, considering various data types (`float`, `double`, `int`, `short`, `signed char`). Investigate whether the C implementation demonstrates significant speed advantages over Java.
> 对 C 语言和 Java 实现进行性能比较。分析并解释观察到的任何性能差异，考虑各种数据类型（float、double、int、short、signed char）。研究 C 语言实现是否比 Java 表现出显著的速度优势。

4. Extend the analysis to identify noteworthy patterns or insights, such as performance variations across different data types, impact of language-specific optimizations, memory usage characteristics.
> 扩展分析以识别值得关注的模式或见解，例如不同数据类型之间的性能差异、特定于语言的优化的影响、内存使用特征。

## Tips:

1. As efficicomputational efficiency is the primary focus, you can use randomly generated vector values.
> 由于高效计算效率是首要关注点，你可以使用随机生成的向量值。
2. Use native data types directly. No custom arbitrary-precision types are required.
> 直接使用原生数据类型。不需要自定义的任意精度类型。
1. Employ precise timing mechanisms: 
    * In C: Use `<time.h>` functions. But be careful that function `clock()` may not provide correct time.
    * In Java: Utilize `System.nanoTime()`
    > 使用精确的计时机制：
・在 C 语言中：使用 <time.h> 函数。但要注意，clock () 函数可能无法提供正确的时间。
・在 Java 中：利用 System.nanoTime ()

## Rules:

1. The project report and the source code must be submitted before the deadline. Any submission after the deadline (even by 1 second) will result in **a score of 0**. The deadline is 23:59 on March 30.

1. The files should be submitted as report.pdf, dotproduct.c, and Dotproduct.java. Use exact filename capitalization and extensions. The files should **NOT** be compressed into one.

1. The score will depend on the quality of both the source code and the report. The report should be easy to understand and provide a clear description of the project, especially the highlights. 

1. Attention should be paid to code style. Adequate time is given for code to be written correctly and with good style. Deductions will be made for poor code style. Code style guides, such as the Google C++ Style Guide (http://google.github.io/styleguide/cppguide.html), can be used as a reference. 

