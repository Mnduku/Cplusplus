#include <iostream>
using namespace std;

class shape{
    public:
       virtual ~shape();
       virtual double getperimeter() = 0;
       virtual double getarea() = 0;
       shape();
    private:
    protected:
};

class triangle: public shape{
    public:
       triangle();
       triangle(double a, double b, double c, double d, double e);
       double getperimeter();
       double getarea();
    private:
       double height;
       double base;
       double side1;
       double side2;
       double side3;
};

class circle: public shape{
    public:
       circle();
       circle(double a);
       double getperimeter();
       double getarea();
    private:
       double radius;
       double diameter;
};

class square: public shape{
    public:
       square();
       square(double a);
       double getperimeter();
       double getarea();
    private:
       double sides;
};

class trapezoid: public shape{
    public:
       trapezoid();
       trapezoid(double a, double b, double c, double d, double e);
       double getperimeter();
       double getarea();
    private:
        double base1;
        double base2;
        double height;
        double side3;
        double side4;
};
