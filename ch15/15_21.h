/*
 * @Author: Nimrod
 * @Date: 2018-04-27 21:27:50
 */
#include <iostream>
#include <string>

class Shape {
public:
    typedef std::pair<double, double> Coordinate;
    Shape() = default;
    Shape(const std::string& n) : name(n) {}
    virtual ~Shape() = default;

private:
    std::string name;
};

class Rectangle : public Shape {
public:
    Rectangle() = default;
    Rectangle(const std::string& n, const Coordinate& a, const Coordinate& b,
              const Coordinate& c, const Coordinate& d)
        : Shape(n), a(a), b(b), c(c), d(d) {}

    ~Rectangle() = default;

protected:
    Coordinate a;
    Coordinate b;
    Coordinate c;
    Coordinate d;
};

class Square : public Rectangle {
public:
    Square() = default;
    Square(const std::string& n, const Coordinate& a, const Coordinate& b,
           const Coordinate& c, const Coordinate& d)
        : Rectangle(n, a, b, c, d) {}

    ~Square() = default;
};