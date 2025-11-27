#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <vector>
#include <stdexcept>

template<class T>
class Array {
private:
    std::vector<std::shared_ptr<T>> data;

public:
    Array();
    ~Array() = default;
    
    Array(const Array& other);
    Array& operator=(const Array& other);
    
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;
    
    void addFigure(std::shared_ptr<T> figure);
    void removeFigure(int index);
    double totalArea() const;
    void printAllFigures(std::ostream& os) const;
    
    size_t size() const;
    std::shared_ptr<T> operator[](int index) const;
    void clear();
};

#endif