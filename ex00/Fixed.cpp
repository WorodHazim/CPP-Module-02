/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:47:49 by wuabdull          #+#    #+#             */
/*   Updated: 2026/01/21 17:08:37 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
Fixed::Fixed()
{
    fixedPoint = 0;
    std::cout<<"Default constructor called"<<std::endl;
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