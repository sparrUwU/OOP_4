#include "../include/array.hpp"
#include <iostream>

template<class T>
Array<T>::Array() = default;

template<class T>
Array<T>::Array(const Array& other) {
    for (const auto& item : other.data) {
        data.push_back(std::make_shared<T>(*item));
    }
}

template<class T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        data.clear();
        for (const auto& item : other.data) {
            data.push_back(std::make_shared<T>(*item));
        }
    }
    return *this;
}

template<class T>
Array<T>::Array(Array&& other) noexcept = default;

template<class T>
Array<T>& Array<T>::operator=(Array&& other) noexcept = default;

template<class T>
void Array<T>::addFigure(std::shared_ptr<T> figure) {
    if (!figure) {
        throw std::invalid_argument("Cannot add null figure");
    }
    data.push_back(figure);
}

template<class T>
void Array<T>::removeFigure(int index) {
    if (index < 0 || index >= static_cast<int>(data.size())) {
        throw std::out_of_range("Index out of range");
    }
    data.erase(data.begin() + index);
}

template<class T>
double Array<T>::totalArea() const {
    double total = 0;
    for (const auto& figure : data) {
        total += figure->area();
    }
    return total;
}

template<class T>
void Array<T>::printAllFigures(std::ostream& os) const {
    for (size_t i = 0; i < data.size(); ++i) {
        os << "Figure " << i << ": " << *data[i] << std::endl;
    }
}

template<class T>
size_t Array<T>::size() const { 
    return data.size(); 
}

template<class T>
std::shared_ptr<T> Array<T>::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(data.size())) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<class T>
void Array<T>::clear() {
    data.clear();
}