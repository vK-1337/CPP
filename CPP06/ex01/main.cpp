#include "Serialization.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
    Data test;

    test.stupid_stuff = "stupid stuff";

    std::cout << Serialization::deserialize(Serialization::serialize(&test))->stupid_stuff << std::endl ;

    return EXIT_SUCCESS;
}