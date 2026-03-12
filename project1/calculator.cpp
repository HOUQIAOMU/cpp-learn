#include "calculator.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <expression>\n";
        return 1;
    }

    Calculator calc(argv[1]);
    calc.print_result();

    return 0;
}
