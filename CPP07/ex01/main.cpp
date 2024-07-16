#include "iter.hpp"

void *increment(int &i) {
    i++;
    return (0);
}

void *transform(std::string &s) {
    s = "World";
    return (0);
}

int main(void)
{
    int *a = new int[5];


    for (int i = 0; i < 5; i++)
        a[i] = i;

    for (int i = 0; i < 5; i++)
        std::cout << a[i] << std::endl;

    std::cout << std::endl;

    iter(a, 5, increment);

    for (int i = 0; i < 5; i++)
        std::cout << a[i] << std::endl;

    delete[] a;

    std::cout << std::endl;
    
    std::string *b = new std::string[5];

    for (int i = 0; i < 5; i++)
        b[i] = "Hello";

    for (int i = 0; i < 5; i++)
        std::cout << b[i] << std::endl;

    std::cout << std::endl;

    iter(b, 5, transform);

    for (int i = 0; i < 5; i++)
        std::cout << b[i] << std::endl;

    delete[] b;

    return (0);
}
