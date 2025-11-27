#include "../include/hexagon.hpp"
#include <iostream>
#include <stdexcept>

template<Scalar T>
Hexagon<T>::Hexagon() = default;

template<Scalar T>
Hexagon<T>::Hexagon(const std::vector<Point<T>>& points) {
    createFromPoints(points);
}

template<Scalar T>
Point<T> Hexagon<T>::center() const {
    T sum_x = 0, sum_y = 0;
    for (const auto& vertex : this->vertices) {
        sum_x += vertex->getX();
        sum_y += vertex->getY();
    }
    return Point<T>(sum_x / 6, sum_y / 6);
}

template<Scalar T>
double Hexagon<T>::area() const {
    double area = 0.0;
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        size_t j = (i + 1) % this->vertices.size();
        area += this->vertices[i]->getX() * this->vertices[j]->getY();
        area -= this->vertices[j]->getX() * this->vertices[i]->getY();
    }
    return std::abs(area) / 2.0;
}

template<Scalar T>
void Hexagon<T>::print(std::ostream& os) const {
    os << "Hexagon vertices: ";
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        os << *this->vertices[i];
        if (i < this->vertices.size() - 1) os << " ";
    }
    os << " | Center: " << center() << " | Area: " << area();
}

template<Scalar T>
void Hexagon<T>::read(std::istream& is) {
    std::cout << "Enter 6 points for hexagon: ";
    std::vector<Point<T>> points;
    for (int i = 0; i < 6; ++i) {
        Point<T> p;
        is >> p;
        points.push_back(p);
    }
    createFromPoints(points);
}

template<Scalar T>
bool Hexagon<T>::operator==(const Figure<T>& other) const {
    const Hexagon<T>* hexagon = dynamic_cast<const Hexagon<T>*>(&other);
    if (!hexagon) return false;
    
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        if (*this->vertices[i] != *hexagon->vertices[i]) {
            return false;
        }
    }
    return true;
}

template<Scalar T>
void Hexagon<T>::createFromPoints(const std::vector<Point<T>>& points) {
    if (points.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 points");
    }
    
    this->vertices.clear();
    for (const auto& point : points) {
        this->vertices.push_back(std::make_unique<Point<T>>(point));
    }
}