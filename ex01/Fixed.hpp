/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 02:49:38 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/24 02:49:39 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>   
class Fixed
{
private:
    int fixedPoint;
    static const int fractlBits = 8;
public:
    Fixed();
    Fixed(const int input);
    Fixed(const float input);
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed &src);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& f);
#endif
