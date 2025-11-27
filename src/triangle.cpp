#include "../include/triangle.hpp"
#include <iostream>

template<Scalar T>
Triangle<T>::Triangle() = default;

template<Scalar T>
Triangle<T>::Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    createFromPoints(a, b, c);
}

template<Scalar T>
Point<T> Triangle<T>::center() const {
    T sum_x = 0, sum_y = 0;
    for (const auto& vertex : this->vertices) {
        sum_x += vertex->getX();
        sum_y += vertex->getY();
    }
    return Point<T>(sum_x / 3, sum_y / 3);
}

template<Scalar T>
double Triangle<T>::area() const {
    const T& x1 = this->vertices[0]->getX();
    const T& y1 = this->vertices[0]->getY();
    const T& x2 = this->vertices[1]->getX();
    const T& y2 = this->vertices[1]->getY();
    const T& x3 = this->vertices[2]->getX();
    const T& y3 = this->vertices[2]->getY();
    
    return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

template<Scalar T>
void Triangle<T>::print(std::ostream& os) const {
    os << "Triangle vertices: ";
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        os << *this->vertices[i];
        if (i < this->vertices.size() - 1) os << " ";
    }
    os << " | Center: " << center() << " | Area: " << area();
}

template<Scalar T>
void Triangle<T>::read(std::istream& is) {
    std::cout << "Enter 3 points for triangle (x1 y1 x2 y2 x3 y3): ";
    Point<T> a, b, c;
    is >> a >> b >> c;
    createFromPoints(a, b, c);
}

template<Scalar T>
bool Triangle<T>::operator==(const Figure<T>& other) const {
    const Triangle<T>* triangle = dynamic_cast<const Triangle<T>*>(&other);
    if (!triangle) return false;
    
    return Figure<T>::operator==(other);
}

template<Scalar T>
void Triangle<T>::createFromPoints(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    this->vertices.clear();
    this->vertices.push_back(std::make_unique<Point<T>>(a));
    this->vertices.push_back(std::make_unique<Point<T>>(b));
    this->vertices.push_back(std::make_unique<Point<T>>(c));
}

template class Triangle<double>;
template class Triangle<float>;