#include <iostream>
#include "Figures.h"
#include "vector"
#include "memory"

int main() {
std::vector<std::unique_ptr<TriangleAbstract>> triangles ;
triangles.push_back(std::make_unique<Triangle>(3, 4, 5, 30, 60, 90));
triangles.push_back(std::make_unique<IsoscelesTriangle>(12, 20, 30, 120));
triangles.push_back(std::make_unique<EquilateralTriangle>(30));
triangles.push_back(std::make_unique<RightTriangle>(6,8, 10, 30, 60));

for(const auto &triangle: triangles) {
    std::cout << triangle->GetName() << std::endl
              << (triangle->IsRight() ? "Правильная" : "Неправильная") << std::endl
              << triangle->GetSidesData() << std::endl
              << triangle->GetAnglesData() << std::endl << std::endl;
}

std::vector<std::unique_ptr<QuadrupleAbstract>> quadruples;

quadruples.push_back(std::make_unique<Rectangle>(10, 20));
quadruples.push_back(std::make_unique<Square>(100));
quadruples.push_back(std::make_unique<Parallelogram>(100, 200, 70,110));
quadruples.push_back(std::make_unique<Rhombus>(100, 40, 140));

for(const auto &quad: quadruples) {
    std::cout << quad->GetName() << std::endl
            << (quad->IsRight() ? "Правильная" : "Неправильная") << std::endl
            << quad->GetSidesData() << std::endl
            << quad->GetAnglesData() << std::endl << std::endl;
}
}