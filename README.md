# CPP-Module-02
Fixed-Point Arithmetic, Operator Overloading & BSP

![C++](https://img.shields.io/badge/Language-C++98-blue)
![42](https://img.shields.io/badge/School-42-black)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![Standard](https://img.shields.io/badge/Standard-C++98-orange)

---

## Overview
This project is part of the 42 C++ curriculum.

Module 02 focuses on:
* Orthodox Canonical Form
* Operator Overloading
* Fixed-point arithmetic
* Static members
* Const correctness
* Binary Space Partitioning (BSP)

Instead of relying on built-in floating-point numbers, we implement our own Fixed-point number type and use it for precise arithmetic and geometric calculations.

## Part I — Fixed-Point Numbers
❓ What is Fixed-Point?
A fixed-point number stores real values using integers.

* Instead of storing:
<pre>
42.42
</pre>

We store:

<pre>
42.42 × 256 = 10860
</pre>

Because:
<pre>
2^8 = 256
</pre>
We reserve 8 fractional bits.

---

Internal Representation
<pre>
class Fixed {
private:
    int fixedPoint;
    static const int fractlBits = 8;
};
</pre>
The real value is interpreted as:

<pre>
real_value = fixedPoint / 256
</pre>
---

Conversion Rules

| Operation  | Behavior |
| ------------- |:-------------:|
| Fixed(int)      | value << 8     |
| Fixed(float)      | roundf(value × 256)     |
| toFloat()      | fixedPoint >> 8     |
| toInt()	     | fixedPoint >> 8     |


 Bit Layout (Conceptual)
<pre>
| Integer Part | Fractional Part |
|--------------|----------------|
| 24 bits      | 8 bits         |
</pre>
The lowest 8 bits represent fractional precision.

Smallest representable value:
<pre>
ε = 1 / 256 = 0.00390625
</pre>

---

## Part II — Operator Overloading

Comparison Operators
> < >= <= == !=

Comparison works directly on stored integers because scaling is consistent.

➕ Addition / Subtraction
<pre>
result = a.fixedPoint ± b.fixedPoint
</pre>
No rescaling needed.

✖ Multiplication

Stored values:
<pre>
A = a × 256
B = b × 256
</pre>

Multiplying:
<pre>
A × B = a × b × 256²
</pre>

To restore scaling:
<pre>
result = (A × B) >> 8
 </pre>
➗ Division

To preserve precision:
<pre>
result = (A << 8) / B
</pre>

Increment / Decrement
++a

Increases raw value by:
<pre>
1 → 0.00390625
</pre>
---

## UML Diagram
<pre>
Class: Fixed
+----------------------------------+
|              Fixed               |
+----------------------------------+
| - fixedPoint : int               |
| - fractlBits : static const int  |
+----------------------------------+
| + Fixed()                        |
| + Fixed(int)                     |
| + Fixed(float)                   |
| + Fixed(const Fixed&)            |
| + operator=()                    |
| + ~Fixed()                       |
| + toFloat() : float              |
| + toInt() : int                  |
| + operator + - * /               |
| + operator > < >= <= == !=       |
| + operator ++ --                 |
| + min() / max()                  |
+----------------------------------+
</pre>

Class: Point

<pre>
+-------------------------+
|         Point           |
+-------------------------+
| - _x : const Fixed      |
| - _y : const Fixed      |
+-------------------------+
| + Point()               |
| + Point(float,float)    |
| + Point(const Point&)   |
| + ~Point()              |
| + getX() : Fixed        |
| + getY() : Fixed        |
+-------------------------+
</pre>

## Part III — BSP (Binary Space Partitioning)
Goal
Determine if a point is strictly inside a triangle.

Conditions:
* On edge → false
* On vertex → false
* Inside → true

Geometry Concept
We use the 2D cross product:

<pre>
cross(A,B,P) =
(Bx - Ax)*(Py - Ay)
-
(By - Ay)*(Px - Ax)
</pre>

Orientation Meaning
<pre>
cross > 0   → Left side
cross < 0   → Right side
cross = 0   → Collinear
</pre>

Triangle Visualization (ASCII)

Example triangle:
<pre>

C(0,6)
|\
| \
|  \
|   \
|    \
A-----B
(0,0) (6,0)
</pre>
---

BSP Algorithm

We compute:
<pre>
c1 = cross(A,B,P)
c2 = cross(B,C,P)
c3 = cross(C,A,P)
</pre>

Decision logic:
<pre>
if any == 0 → OUTSIDE
if all positive → INSIDE
if all negative → INSIDE
else → OUTSIDE
</pre>

## Why It Works
Each edge divides the plane into two half-spaces.
For a convex polygon (triangle):
A point is inside if it lies in the same half-space for all edges.
