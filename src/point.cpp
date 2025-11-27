#include "../include/point.hpp"
#include <cmath>

template<Scalar T>
Point<T>::Point() : x(0), y(0) {}

template<Scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<Scalar T>
T Point<T>::getX() const { return x; }

template<Scalar T>
T Point<T>::getY() const { return y; }

template<Scalar T>
void Point<T>::setX(T x) { this->x = x; }

template<Scalar T>
void Point<T>::setY(T y) { this->y = y; }

template<Scalar T>
double Point<T>::distanceTo(const Point<T>& other) const {
    T dx = x - other.x;
    T dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

template<Scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return std::abs(x - other.x) < 1e-6 && std::abs(y - other.y) < 1e-6;
}