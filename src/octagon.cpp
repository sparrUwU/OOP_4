#include "../include/octagon.hpp"
#include <iostream>
#include <stdexcept>

template<Scalar T>
Octagon<T>::Octagon() = default;

template<Scalar T>
Octagon<T>::Octagon(const std::vector<Point<T>>& points) {
    createFromPoints(points);
}

template<Scalar T>
Point<T> Octagon<T>::center() const {
    T sum_x = 0, sum_y = 0;
    for (const auto& vertex : this->vertices) {
        sum_x += vertex->getX();
        sum_y += vertex->getY();
    }
    return Point<T>(sum_x / 8, sum_y / 8);
}

template<Scalar T>
double Octagon<T>::area() const {
    // Формула площади многоугольника по координатам вершин
    double area = 0.0;
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        size_t j = (i + 1) % this->vertices.size();
        area += this->vertices[i]->getX() * this->vertices[j]->getY();
        area -= this->vertices[j]->getX() * this->vertices[i]->getY();
    }
    return std::abs(area) / 2.0;
}

template<Scalar T>
void Octagon<T>::print(std::ostream& os) const {
    os << "Octagon vertices: ";
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        os << *this->vertices[i];
        if (i < this->vertices.size() - 1) os << " ";
    }
    os << " | Center: " << center() << " | Area: " << area();
}

template<Scalar T>
void Octagon<T>::read(std::istream& is) {
    std::cout << "Enter 8 points for octagon: ";
    std::vector<Point<T>> points;
    for (int i = 0; i < 8; ++i) {
        Point<T> p;
        is >> p;
        points.push_back(p);
    }
    createFromPoints(points);
}

template<Scalar T>
bool Octagon<T>::operator==(const Figure<T>& other) const {
    const Octagon<T>* octagon = dynamic_cast<const Octagon<T>*>(&other);
    if (!octagon) return false;
    
    for (size_t i = 0; i < this->vertices.size(); ++i) {
        if (*this->vertices[i] != *octagon->vertices[i]) {
            return false;
        }
    }
    return true;
}

template<Scalar T>
void Octagon<T>::createFromPoints(const std::vector<Point<T>>& points) {
    if (points.size() != 8) {
        throw std::invalid_argument("Octagon must have exactly 8 points");
    }
    
    this->vertices.clear();
    for (const auto& point : points) {
        this->vertices.push_back(std::make_unique<Point<T>>(point));
    }
}