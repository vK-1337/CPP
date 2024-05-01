#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
  private:
	int _RawBits;
	static const int _Fract = 8;

  public:
	Fixed();
	Fixed(const Fixed &source);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	Fixed &operator=(const Fixed &source);

    // COMPARISON OPERATORS //
    
    bool operator>(const Fixed fixed);
    bool operator<(const Fixed fixed);
    bool operator>=(const Fixed fixed);
    bool operator<=(const Fixed fixed);
    bool operator==(const Fixed fixed);
    bool operator!=(const Fixed fixed);

    // ARITHMETICS OPERATORS //

    Fixed   operator+( const Fixed &rhs ) const ;
    Fixed   operator-( const Fixed &rhs ) const ;
    Fixed   operator*( const Fixed &rhs ) const ;
    Fixed   operator/( const Fixed &rhs ) const ;

    // INCR && DECR //

    Fixed&  operator++( void ); // prefix
    Fixed   operator++( int ); // postfix
    Fixed&  operator--( void ); // prefix
    Fixed   operator--( int ); // postfix

    static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);

#endif