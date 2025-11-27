#include <iostream>
#include <memory>
#include "../include/point.hpp"
#include "../include/figure.hpp"
#include "../include/triangle.hpp"
#include "../include/hexagon.hpp"
#include "../include/octagon.hpp"
#include "../include/array.hpp"

int main() {
    // Демонстрация работы с Array<Figure<double>>
    Array<std::shared_ptr<Figure<double>>> figureArray;
    
    // Создаем фигуры по точкам
    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0, 0), 
        Point<double>(4, 0), 
        Point<double>(2, 3)
    );
    
    auto hexagon = std::make_shared<Hexagon<double>>(std::vector<Point<double>>{
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 1),
        Point<double>(2, 2),
        Point<double>(1, 2),
        Point<double>(0, 1)
    });
    
    auto octagon = std::make_shared<Octagon<double>>(std::vector<Point<double>>{
        Point<double>(1, 0),
        Point<double>(2, 0),
        Point<double>(3, 1),
        Point<double>(3, 2),
        Point<double>(2, 3),
        Point<double>(1, 3),
        Point<double>(0, 2),
        Point<double>(0, 1)
    });
    
    // Добавляем в массив
    figureArray.addFigure(triangle);
    figureArray.addFigure(hexagon);
    figureArray.addFigure(octagon);
    
    std::cout << "All figures:" << std::endl;
    figureArray.printAllFigures(std::cout);
    std::cout << "Total area: " << figureArray.totalArea() << std::endl;
    
    // Демонстрация удаления
    std::cout << "\nAfter removing figure at index 1:" << std::endl;
    figureArray.removeFigure(1);
    figureArray.printAllFigures(std::cout);
    std::cout << "Total area after removal: " << figureArray.totalArea() << std::endl;
    
    // Демонстрация работы с конкретным типом
    Array<std::shared_ptr<Triangle<double>>> triangleArray;
    triangleArray.addFigure(std::make_shared<Triangle<double>>(
        Point<double>(0, 0), 
        Point<double>(2, 0), 
        Point<double>(1, 1)
    ));
    std::cout << "\nTriangle array size: " << triangleArray.size() << std::endl;
    
    // Интерактивный ввод
    std::cout << "\n=== Interactive Input ===" << std::endl;
    std::shared_ptr<Figure<double>> newFigure;
    
    int choice;
    std::cout << "Choose figure type (1-Triangle, 2-Hexagon, 3-Octagon): ";
    std::cin >> choice;
    
    try {
        switch (choice) {
            case 1: {
                auto newTriangle = std::make_shared<Triangle<double>>();
                std::cin >> *newTriangle;
                newFigure = newTriangle;
                break;
            }
            case 2: {
                auto newHexagon = std::make_shared<Hexagon<double>>();
                std::cin >> *newHexagon;
                newFigure = newHexagon;
                break;
            }
            case 3: {
                auto newOctagon = std::make_shared<Octagon<double>>();
                std::cin >> *newOctagon;
                newFigure = newOctagon;
                break;
            }
            default:
                std::cout << "Invalid choice!" << std::endl;
                return 1;
        }
        
        figureArray.addFigure(newFigure);
        std::cout << "Figure added successfully!" << std::endl;
        figureArray.printAllFigures(std::cout);
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}