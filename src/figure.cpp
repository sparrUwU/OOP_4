#include "../include/figure.hpp"

template<Scalar T>
Figure<T>::Figure() = default;

template<Scalar T>
Figure<T>::Figure(const Figure<T>& other) {
    for (const auto& vertex : other.vertices) {
        vertices.push_back(std::make_unique<Point<T>>(*vertex));
    }
}

template<Scalar T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
    if (this != &other) {
        vertices.clear();
        for (const auto& vertex : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(*vertex));
        }
    }
    return *this;
}

template<Scalar T>
Figure<T>::Figure(Figure<T>&& other) noexcept 
    : vertices(std::move(other.vertices)) {}

template<Scalar T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

template<Scalar T>
const std::vector<std::unique_ptr<Point<T>>>& Figure<T>::getVertices() const { 
    return vertices; 
}

template<Scalar T>
bool Figure<T>::operator==(const Figure<T>& other) const {
    if (vertices.size() != other.vertices.size()) {
        return false;
    }
    
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (*vertices[i] != *other.vertices[i]) {
            return false;
        }
    }
    return true;
}

template<Scalar T>
Figure<T>::operator double() const { 
    return area(); 
}