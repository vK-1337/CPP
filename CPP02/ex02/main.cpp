#include <iostream>
#include "Fixed.hpp"

int main( void ) {



    std::cout << std::endl << "Tests for limits with int constructor" << std::endl;
    std::cout << Fixed(-8388609) << std::endl;
    std::cout << Fixed(-8388608) << std::endl;
    std::cout << Fixed(8388608) << std::endl;
    std::cout << Fixed(8388607) << std::endl;

    std::cout << std::endl << "Tests for limits with float constructor" << std::endl;
    std::cout << Fixed(-8388609.0f) << std::endl;
    std::cout << Fixed(-8388608.0f) << std::endl;
    std::cout << Fixed(8388608.0f) << std::endl;
    std::cout << Fixed(8388607.0f) << std::endl;

    std::cout << std::endl << "Tests for comparisons operators" << std::endl;

    std::cout << std::endl << "Is 10 < 9 ?" << std::endl;
    std::cout << (Fixed(10) < Fixed(9) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 9 < 10 ?" << std::endl;
    std::cout << (Fixed(9) < Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 10 > 9 ?" << std::endl;
    std::cout << (Fixed(10) > Fixed(9) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 9 > 10 ?" << std::endl;
    std::cout << (Fixed(9) > Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 9 <= 10 ?" << std::endl;
    std::cout << (Fixed(9) <= Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 10 <= 10 ?" << std::endl;
    std::cout << (Fixed(10) <= Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 11 <= 10 ?" << std::endl;
    std::cout << (Fixed(11) <= Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 11 >= 10 ?" << std::endl;
    std::cout << (Fixed(10) >= Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 10 >= 10 ?" << std::endl;
    std::cout << (Fixed(10) >= Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 9 >= 10 ?" << std::endl;
    std::cout << (Fixed(9) >= Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 10 == 10 ?" << std::endl;
    std::cout << (Fixed(10) == Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 9 == 10 ?" << std::endl;
    std::cout << (Fixed(9) == Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 10 != 10 ?" << std::endl;
    std::cout << (Fixed(10) != Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout << std::endl << "Is 9 != 10 ?" << std::endl;
    std::cout << (Fixed(9) != Fixed(10) ? "Yes" : "No") << std::endl;

    std::cout <<std::endl << "Tests for multiplication max" << std::endl;
    std::cout << Fixed(2896) * Fixed(2896) << std::endl;
    std::cout << Fixed(2897) * Fixed(2897) << std::endl;

    std::cout <<std::endl << "Tests for division max" << std::endl;
    std::cout << Fixed(1) / Fixed(0.0003f) << std::endl;
    std::cout << Fixed(2500) / Fixed(12) << std::endl;

    std::cout <<std::endl << "Tests for addition max" << std::endl;
    std::cout << Fixed(8388607.0f) + Fixed(10) << std::endl;
    std::cout << Fixed(42) + Fixed(42) << std::endl;

    std::cout <<std::endl << "Tests for soustraction max" << std::endl;
    std::cout << Fixed(-8388607.0f) - Fixed(10) << std::endl;
    std::cout << Fixed(42) - Fixed(43) << std::endl;

    std::cout << std::endl << "|| SECOND PART OF THE MAIN (FROM 42 SUBJECT) ||" << std::endl << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}