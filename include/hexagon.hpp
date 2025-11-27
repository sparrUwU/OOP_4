#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.hpp"

template<Scalar T>
class Hexagon : public Figure<T> {
public:
    Hexagon();
    Hexagon(const std::vector<Point<T>>& points);
    
    Point<T> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    bool operator==(const Figure<T>& other) const override;

private:
    void createFromPoints(const std::vector<Point<T>>& points);
};

#endif