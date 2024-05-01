#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _RawBits;
        static const int _Fract = 8;
    public:
        Fixed();
        Fixed(const Fixed& source);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed& operator=(const Fixed& source);
};

#endif
