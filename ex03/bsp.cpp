/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:57:05 by wuabdull          #+#    #+#             */
/*   Updated: 2026/01/21 16:57:08 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
static Fixed cross(Point const& a, Point const& b, Point const& p)
{
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed apx = p.getX() - a.getX();
    Fixed apy = p.getY() - a.getY();
    return (abx * apy) - (aby * apx);
}
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed c1 = cross(a, b, point);
    Fixed c2 = cross(b, c, point);
    Fixed c3 = cross(c, a, point);
    if (c1 == 0 || c2 == 0 || c3 == 0)
        return false;
    bool allPos = (c1 > 0 && c2 > 0 && c3 > 0);
    bool allNeg = (c1 < 0 && c2 < 0 && c3 < 0);
    return (allPos || allNeg);
}
