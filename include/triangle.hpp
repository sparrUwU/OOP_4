#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.hpp"

template<Scalar T>
class Triangle : public Figure<T> {
public:
    Triangle();
    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c);
    
    Point<T> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    bool operator==(const Figure<T>& other) const override;

private:
    void createFromPoints(const Point<T>& a, const Point<T>& b, const Point<T>& c);
};

#endif