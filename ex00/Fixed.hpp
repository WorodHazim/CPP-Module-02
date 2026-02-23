/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 02:46:28 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/24 02:46:29 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
private:
    int fixedPoint;
    static const int fractlBits = 8 ;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed &src);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
#endif
