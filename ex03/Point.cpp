/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:20:43 by wuabdull          #+#    #+#             */
/*   Updated: 2026/01/21 17:20:46 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
Point::Point() : _x(0), _y(0) {}
Point::Point(float x, float y) : _x(x), _y(y) {}
Point::Point(Point const& other) : _x(other._x), _y(other._y) {}
Point::~Point() {}
Fixed Point::getX() const
{
    return _x;
}
Fixed Point::getY() const
{
    return _y;
}
