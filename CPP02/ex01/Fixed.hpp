#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

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
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);

#endif