#ifndef FIGURE_H
#define FIGURE_H
#include "point.hpp"
#include <memory>
#include <vector>

template<Scalar T>
class Figure {
protected:
    std::vector<std::unique_ptr<Point<T>>> vertices;

public:
    Figure();
    virtual ~Figure() = default;
    
    Figure(const Figure<T>& other);
    Figure<T>& operator=(const Figure<T>& other);
    
    Figure(Figure<T>&& other) noexcept;
    Figure<T>& operator=(Figure<T>&& other) noexcept;

    const std::vector<std::unique_ptr<Point<T>>>& getVertices() const;

    virtual Point<T> center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    virtual bool operator==(const Figure<T>& other) const = 0;
    virtual operator double() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& fig) {
        fig.print(os);
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Figure<T>& fig) {
        fig.read(is);
        return is;
    }
};

#endif