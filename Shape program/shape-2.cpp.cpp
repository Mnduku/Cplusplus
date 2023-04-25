#include <iostream>
#include <cmath>
#include "shape.h"
using namespace std;

shape::shape(){
}
triangle::triangle(double a, double b, double c, double d, double e){
    height = a;
    base = b;
    side1 = c;
    side2 = d;
    side3 = e;
}
double triangle::getperimeter(){
    double peri;
    peri = side1 + side2 + side3;
    cout << "\nThe perimeter is " << peri;
    return peri;
}
double triangle::getarea(){
    double area;
    area = base * height;
    area = area/2;
    cout << "\nThe area is " << area;
    return area;
}
circle::circle(double a){
    radius = a;
    diameter = a * 2;
}
double circle::getperimeter(){
    double peri;
    peri = diameter * 3.141592653;\
    cout << "\nThe perimeter is " << peri;
    return peri;
}
double circle::getarea(){
    double area;
    area = pow(radius, 2);
    area = area * 3.141592653;
    cout << "\nThe area is " << area;
    return area;
}
square::square(double a){
    sides = a;
}
double square::getperimeter(){
    double peri;
    peri = sides * 4;
    cout << "\nThe perimeter is " << peri;
    return peri;
}
double square::getarea(){
    double area;
    area = pow(sides, 2);
    cout << "\nThe area is " << area;
    return area;
}
trapezoid::trapezoid(double a, double b, double c, double d, double e){
    base1 = a;
    base2 = b;
    height = c;
    side3 = d;
    side4 = e;
}
double trapezoid::getperimeter(){
    double peri;
    peri = base1 + base2 + side3 + side4;
    cout << "\nThe perimeter is " << peri;
    return peri;
}
double trapezoid::getarea(){
    double area;
    area = base1 + base2;
    area = area/2;
    area = area * height;
    cout << "\nThe area is " << area;
    return area;
}
shape::~shape(){
}
