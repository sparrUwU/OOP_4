#include <gtest/gtest.h>
#include <memory>
#include "../include/point.hpp"
#include "../include/figure.hpp"
#include "../include/triangle.hpp"
#include "../include/hexagon.hpp"
#include "../include/octagon.hpp"
#include "../include/array.hpp"

// Тесты для Point
TEST(PointTest, ConstructionAndEquality) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(3.0, 4.0);
    
    EXPECT_EQ(p1, p2);
    EXPECT_NE(p1, p3);
}

TEST(PointTest, DistanceCalculation) {
    Point<double> p1(0.0, 0.0);
    Point<double> p2(3.0, 4.0);
    
    EXPECT_DOUBLE_EQ(p1.distanceTo(p2), 5.0);
}

// Тесты для Triangle
TEST(TriangleTest, AreaCalculation) {
    Triangle<double> triangle(
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(2, 3)
    );
    
    EXPECT_DOUBLE_EQ(triangle.area(), 6.0);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle<double> triangle(
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(2, 3)
    );
    
    Point<double> center = triangle.center();
    EXPECT_DOUBLE_EQ(center.getX(), 2.0);
    EXPECT_DOUBLE_EQ(center.getY(), 1.0);
}

// Тесты для Hexagon
TEST(HexagonTest, AreaCalculation) {
    Hexagon<double> hexagon(std::vector<Point<double>>{
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 1),
        Point<double>(2, 2),
        Point<double>(1, 2),
        Point<double>(0, 1)
    });
    
    EXPECT_GT(hexagon.area(), 0.0);
}

// Тесты для Octagon
TEST(OctagonTest, AreaCalculation) {
    Octagon<double> octagon(std::vector<Point<double>>{
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 1),
        Point<double>(3, 2),
        Point<double>(2, 3),
        Point<double>(1, 3),
        Point<double>(0, 2),
        Point<double>(0, 1)
    });
    
    EXPECT_GT(octagon.area(), 0.0);
}

// Тесты для Array
TEST(ArrayTest, AddAndRemoveFigures) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0, 0),
        Point<double>(2, 0),
        Point<double>(1, 1)
    );
    
    array.addFigure(triangle);
    EXPECT_EQ(array.size(), 1);
    
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<std::shared_ptr<Figure<double>>> array;
    
    auto triangle1 = std::make_shared<Triangle<double>>(
        Point<double>(0, 0),
        Point<double>(2, 0),
        Point<double>(1, 1)
    );
    
    auto triangle2 = std::make_shared<Triangle<double>>(
        Point<double>(0, 0),
        Point<double>(3, 0),
        Point<double>(1.5, 2)
    );
    
    array.addFigure(triangle1);
    array.addFigure(triangle2);
    
    double totalArea = array.totalArea();
    EXPECT_GT(totalArea, 0.0);
}

TEST(ArrayTest, CopyAndMoveSemantics) {
    Array<std::shared_ptr<Figure<double>>> original;
    original.addFigure(std::make_shared<Triangle<double>>(
        Point<double>(0, 0),
        Point<double>(2, 0),
        Point<double>(1, 1)
    ));
    
    // Тест копирования
    Array<std::shared_ptr<Figure<double>>> copy = original;
    EXPECT_EQ(copy.size(), original.size());
    
    // Тест перемещения
    Array<std::shared_ptr<Figure<double>>> moved = std::move(original);
    EXPECT_EQ(moved.size(), 1);
    EXPECT_EQ(original.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}