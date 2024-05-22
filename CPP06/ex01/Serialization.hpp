#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serialization {
    private:
        Serialization();
    public:
        ~Serialization();
        Serialization(const Serialization& rhs);
        Serialization& operator=(const Serialization& rhs);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif