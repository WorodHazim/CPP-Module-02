/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:57:27 by wuabdull          #+#    #+#             */
/*   Updated: 2026/01/21 16:58:45 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
Fixed::Fixed()
{
fixedPoint = 0;
}
Fixed::Fixed(const int input)
{
fixedPoint = input << fractlBits;
}
Fixed::Fixed(const float input)
{
fixedPoint = (int)roundf(input * (1 << fractlBits));
}
Fixed::Fixed(const Fixed& other)
{
*this = other;
}
Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->fixedPoint = src.fixedPoint;

    return *this;
}
Fixed::~Fixed() {}
int Fixed::getRawBits(void) const
{
    return fixedPoint;
}
void Fixed::setRawBits( int const raw )
{
    fixedPoint = raw;
}
float Fixed::toFloat(void) const
{
    return fixedPoint / (float)(1 << fractlBits);
}
int  Fixed::toInt(void) const
{
    return fixedPoint >> fractlBits;;
}
std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}
bool Fixed::operator>(const Fixed& other) const
{
    return this->fixedPoint > other.fixedPoint;
}
bool Fixed::operator<(const Fixed& other) const
{
    return this->fixedPoint < other.fixedPoint;
}
bool Fixed::operator>=(const Fixed& other) const
{
    return this->fixedPoint >= other.fixedPoint;
}
bool Fixed::operator<=(const Fixed& other) const
{
    return this->fixedPoint <= other.fixedPoint;
}
bool Fixed::operator==(const Fixed& other) const
{
    return this->fixedPoint == other.fixedPoint;
}
bool Fixed::operator!=(const Fixed& other) const
{
    return this->fixedPoint != other.fixedPoint;
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->fixedPoint - other.fixedPoint);
    return result;
}
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->fixedPoint + other.fixedPoint);
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long tmp = (long)this->fixedPoint * (long)other.fixedPoint;
    result.setRawBits(tmp >> fractlBits);
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long tmp = ((long)this->fixedPoint << fractlBits) / other.fixedPoint;
    result.setRawBits(tmp);
    return result;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    fixedPoint += 1;
    return tmp;
}
Fixed& Fixed::operator--()
{
    fixedPoint -= 1;
    return *this;
}
Fixed& Fixed::operator++()
{
    fixedPoint += 1;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    fixedPoint -= 1;
    return tmp;
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}