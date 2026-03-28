#include <iostream>
#include <random>
#include <chrono>
#include <vector>
// 此文件以比较自定义类和Myvector类点积运算速度性能。
//编译时使用"g++ -O3 -march=native Myvector.cpp"可以启用优化选项，显著提升性能。 

//创建一个模板vector类，实现点乘运算。
template <typename T>
class Myvector
{
    private:
        size_t length;
        T * data;

    public:
        Myvector(size_t len):length(len), data(new T[len]) {}
        // 自定义copy constructor
        Myvector(const Myvector & other): length(other.length), data(new T[other.length])
        {
            for(size_t i = 0; i<length; i++)
            {
                data[i] = other.data[i];
            }
        }

        // 重载赋值运算符，实现Myvector={1,2,3}的功能
        Myvector & operator=(const T * data)
        {
            for(size_t i = 0; i<length; i++)
            {
                this->data[i] = data[i];
            }
            return *this;
        }

        Myvector & operator=(const Myvector & other)
        {
            if(this == &other) return *this; // 自我赋值检查
            delete[] data; // 释放原有资源
            length = other.length;
            data = new T[length];
            for(size_t i = 0; i<length; i++)
            {
                data[i] = other.data[i];
            }
            return *this;
        }

        //重载[]运算符，以满足随机数赋值
        T & operator[](size_t index) const
        {
            return data[index];
        }

        T dot_product(const Myvector & other)
        {
            T result = 0;
            if(length != other.length)
            {
                std::cerr<<"Vectors must be of the same length for dot product.";
            }
            std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
            for(size_t i = 0;i<length; i++)
            {
                result += this->data[i] * other.data[i];
            }
            std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
            //std::cout << "Dot product: " << result << std::endl;
            std::cout << "Time taken: " << time_span.count() << " seconds." << std::endl;
            return result;

        }
        //析构
        ~Myvector() { delete[] data; }
};

// 使用std::vector库实现点积运算。
template <typename T>
T dot_product_for_vector(const std::vector<T> & vec1, const std::vector<T> & vec2)
{
    T result = 0;
    if(vec1.size() != vec2.size())
    {
        std::cerr<<"Vectors must be of the same length for dot product.";
    }
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    for(size_t i = 0; i<vec1.size(); i++)
    {
        result += vec1[i] * vec2[i];
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    //std::cout << "Dot product: " << result << std::endl;
    std::cout << "Use std::vector Time taken: " << time_span.count() << " seconds." << std::endl;
    return result;
}

// 计算int类型点积
void calculate_int_dot_product(size_t len)
{
    std::cout<<"parameter is int:"<<std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10);
    Myvector<int> vec1(len);
    Myvector<int> vec2(len);
    std::vector<int> vec1_(len); //使用std::vector库
    std::vector<int> vec2_(len);
    for(size_t i = 0; i<len; i++)    {
        vec1[i] = dis(gen);
        vec2[i] = dis(gen);
        vec1_[i] = vec1[i];
        vec2_[i] = vec2[i];
    }
    std::cout<<"result for self-defined Myvector class:"<<std::endl;
    int result = vec1.dot_product(vec2);
    std::cout<<"result for std::vector class:"<<std::endl;
    int result_ = dot_product_for_vector(vec1_, vec2_);
    std::cout<<std::endl;


    //std::cout<<"int_dot product: " << result << std::endl;
}

// 计算double类型点积
void calculate_double_dot_product(size_t len)
{
    std::cout<<"parameter is double:"<<std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(1.0, 10.0);
    Myvector<double> vec1(len);
    Myvector<double> vec2(len);
    std::vector<int> vec1_(len); //使用std::vector库
    std::vector<int> vec2_(len);
    for(size_t i = 0; i<len; i++)    {
        vec1[i] = dis(gen);
        vec2[i] = dis(gen);
        vec1_[i] = vec1[i];
        vec2_[i] = vec2[i];
    }
    double result = vec1.dot_product(vec2);
    double result_ = dot_product_for_vector(vec1_, vec2_);
    //std::cout<<"double_dot product: " << result << std::endl;
}

// 计算char类型点积
void calculate_char_dot_product(size_t len)
{
    std::cout<<"parameter is char:"<<std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<char> dis('a', 'z');
    Myvector<char> vec1(len);
    Myvector<char> vec2(len);
    
    for(size_t i = 0; i<len; i++)    {
        vec1[i] = dis(gen);
        vec2[i] = dis(gen);
    }
    double result = vec1.dot_product(vec2);
    std::cout<<"char_dot product: " << result << std::endl;
    
}
int main()
{
    size_t len = 1000000; // 向量长度
    calculate_int_dot_product(len);
    std::cout<<"-------------"<<std::endl;
    calculate_double_dot_product(len);
    std::cout<<"-------------"<<std::endl;
    calculate_char_dot_product(len);
    return 0;
}

