/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:59:53 by wuabdull          #+#    #+#             */
/*   Updated: 2026/01/21 17:00:29 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);
static void test(Point const& a, Point const& b, Point const& c, Point const& p, const std::string& name)
{
    std::cout << name << " -> " << (bsp(a, b, c, p) ? "INSIDE" : "OUTSIDE") << std::endl;
}
int main(void)
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);
    Point p1(2.0f, 2.0f);
    Point p2(10.0f, 10.0f);
    Point p3(5.0f, 0.0f);
    Point p4(0.0f, 0.0f);
    test(a, b, c, p1, "p1 (2,2)");
    test(a, b, c, p2, "p2 (10,10)");
    test(a, b, c, p3, "p3 (5,0) edge");
    test(a, b, c, p4, "p4 (0,0) vertex");
    return 0;
}
