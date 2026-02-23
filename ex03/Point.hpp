/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 03:02:12 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/24 03:02:21 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();                         
    Point(float x, float y);        
    Point(Point const& other);       
    ~Point();
    Fixed getX() const;
    Fixed getY() const;
};
#endif
