#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <concepts>
#include <cmath>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x, y;

public:
    Point();
    Point(T x, T y);

    T getX() const;
    T getY() const;
    void setX(T x);
    void setY(T y);

    double distanceTo(const Point<T>& other) const;
    
    bool operator==(const Point<T>& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Point<T>& p) {
        is >> p.x >> p.y;
        return is;
    }
};


#endif