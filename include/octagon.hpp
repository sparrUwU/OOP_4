#ifndef OCTAGON_H
#define OCTAGON_H
#include "figure.hpp"

template<Scalar T>
class Octagon : public Figure<T> {
public:
    Octagon();
    Octagon(const std::vector<Point<T>>& points);
    
    Point<T> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    bool operator==(const Figure<T>& other) const override;

private:
    void createFromPoints(const std::vector<Point<T>>& points);
};

#endif