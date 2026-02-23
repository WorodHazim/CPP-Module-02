/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 02:49:32 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/24 02:49:33 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
Fixed::Fixed()
{
    fixedPoint = 0;
    std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const int input)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPoint = input << fractlBits;
}
Fixed::Fixed(const float input)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPoint = (int)roundf(input * (1 << fractlBits));
}
Fixed::Fixed(const Fixed& other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}
Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->fixedPoint = src.fixedPoint;
    return *this;
}
Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;
}
void Fixed::setRawBits( int const raw )
{
    fixedPoint = raw;

}
float Fixed::toFloat(void) const
{
return fixedPoint / (float)(1 << fractlBits);;
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
