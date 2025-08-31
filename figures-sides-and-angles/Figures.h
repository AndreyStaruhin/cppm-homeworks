#ifndef CPPM_HOMEWORKS_FIGURES_H
#define CPPM_HOMEWORKS_FIGURES_H
#include "string"
#include <limits>

bool isMachinePrecisionEqual(double a, double b) {
    return std::abs(a - b) < std::numeric_limits<double>::epsilon() *
                             std::max(std::abs(a), std::abs(b));
}

class Figure {
public:
    virtual std::string GetName() = 0;
    virtual int GetSidesCount() = 0;
    virtual bool IsRight() = 0;
};

class TriangleAbstract: public Figure {
public:
    virtual double getSideA() = 0;
    virtual double getSideB() = 0;
    virtual double getSideC() = 0;

    virtual int getAngleA() = 0;
    virtual int getAngleB() = 0;
    virtual int getAngleC() = 0;

    int GetSidesCount()  override final {
        return 3;
    }

    bool IsRight() override final {
        auto a1 = (isMachinePrecisionEqual(getSideA(),getSideB()) && isMachinePrecisionEqual(getSideB(), getSideC()));
        auto a =  getAngleA();
        auto b =  getAngleB();
        auto c =  getAngleC();
        auto x= a == b;
        auto b1 = getAngleA() == getAngleB() == getAngleC();
        return (isMachinePrecisionEqual(getSideA(),getSideB()) && isMachinePrecisionEqual(getSideB(), getSideC()))
               && (getAngleA() == getAngleB()) && (getAngleB() == getAngleC());
    }

    std::string GetSidesData() {
        return std::string("Стороны: a=")
        + std::to_string(getSideA())
        + " b=" + std::to_string(getSideB())
        + " c=" + std::to_string(getSideC());
    }

    std::string GetAnglesData() {
        return std::string("Углы: A=")  + std::to_string(getAngleA())
                                         + " B=" + std::to_string(getAngleB())
                                         + " C=" + std::to_string(getAngleC());
    }
    virtual ~TriangleAbstract(){};
};

class Triangle : public TriangleAbstract {
private:
    const double a;
    const double b;
    const double c;

    const int A;
    const int B;
    const int C;

public:
    Triangle(const double a, const double b, const double c, const int a1, const int b1, const int c1) : a(a), b(b),
                                                                                                         c(c), A(a1),
                                                                                                         B(b1), C(c1) {}
    std::string GetName() override {
        return "Треугольник";
    }

    double getSideA() override {
        return a;
    }

    double getSideB() override {
        return b;
    }

    double getSideC() override {
        return c;
    }

    int getAngleA() override {
        return A;
    }

    int getAngleB() override {
        return B;
    }

    int getAngleC() override {
        return C;
    }

};

class RightTriangle: public TriangleAbstract {
public:
    RightTriangle(double a, double b, double c, int a1, int b1) : a(a), b(b), c(c), A(a1), B(b1) {}
private:
    const double a;
    const double b;
    const double c;

    const int A;
    const int B;
    static const int C = 90;

public:

    std::string GetName() override {
        return "Прямоугольный треугольник:";
    }

    double getSideA() override {
        return a;
    }

    double getSideB() override {
        return b;
    }

    double getSideC() override {
        return c;
    }

    int getAngleA() override {
        return A;
    }

    int getAngleB() override {
        return B;
    }

    int getAngleC() override {
        return C;
    }
};

class EquilateralTriangle: public TriangleAbstract {
public:
    explicit EquilateralTriangle(double a) : a{a} {}

    std::string GetName() override {
        return "Равносторонний треугольник";
    }

    double getSideA() override {
        return a;
    }

    double getSideB() override {
        return a;
    }

    double getSideC() override {
        return a;
    }

    int getAngleA() override {
        return angle;
    }

    int getAngleB() override {
        return angle;
    }

    int getAngleC() override {
        return angle;
    }

private:
    const double a;
    static const int angle = 60;
};

class IsoscelesTriangle: public TriangleAbstract {
private:
    const double leg;
    const double base;

    const int baseAngle;
    const int vertexAngle;
public:
    IsoscelesTriangle(double leg, double base, int baseAngle, int vertexAngle) : leg(leg), base(base), baseAngle(baseAngle), vertexAngle(vertexAngle) {}

    std::string GetName() override {
        return "Равнобедренный треугольник";
    }

    double getSideA() override {
        return leg;
    }

    double getSideB() override {
        return base;
    }

    double getSideC() override {
        return leg;
    }

    int getAngleA() override {
        return baseAngle;
    }

    int getAngleB() override {
        return vertexAngle;
    }

    int getAngleC() override {
        return baseAngle;
    }
};

class QuadrupleAbstract : public Figure {
public:
    virtual double getSideA() = 0;
    virtual double getSideB() = 0;
    virtual double getSideC() = 0;
    virtual double getSideD() = 0;

    virtual int getAngleA() = 0;
    virtual int getAngleB() = 0;
    virtual int getAngleC() = 0;
    virtual int getAngleD() = 0;
    virtual ~QuadrupleAbstract() = default;

    std::string GetSidesData() {
        return std::string("Стороны: a=")
               + std::to_string(getSideA())
               + " b=" + std::to_string(getSideB())
               + " c=" + std::to_string(getSideC())
               + " d=" + std::to_string(getSideD());
    }

    std::string GetAnglesData() {
        return std::string("Углы: A=")  + std::to_string(getAngleA())
               + " B=" + std::to_string(getAngleB())
               + " C=" + std::to_string(getAngleC())
               + " D=" + std::to_string(getAngleD());
    }

    int GetSidesCount() override final {
        return 4;
    }

    bool IsRight() override final {
        return (isMachinePrecisionEqual(getSideA(),getSideB())
                && isMachinePrecisionEqual(getSideB(), getSideC())
                && isMachinePrecisionEqual(getSideC(), getSideD()))

                && (getAngleA() == getAngleB()) && (getAngleB() == getAngleC())
                && (getAngleC() == getAngleD());
    }
};

class Rectangle : public QuadrupleAbstract {
private:
    const double a;
    const double b;
    const double c;
    const double d;

    static const int A = 90;
    static const int B = A;
    static const int C = A;
    static const int D = A;
public:
    Rectangle(const double side1, const double side2): a{side1}, c{side1}, b{side2}, d{side2} {}

    std::string GetName() override {
        return "Прямоугольник";
    }

    double getSideA() override {
        return a;
    }

    double getSideB() override {
        return b;
    }

    double getSideC() override {
        return c;
    }

    double getSideD() override {
        return d;
    }

    int getAngleA() override {
        return A;
    }

    int getAngleB() override {
        return B;
    }

    int getAngleC() override {
        return C;
    }

    int getAngleD() override {
        return D;
    }
};

class Square : public QuadrupleAbstract{
private:
    const double side;
    static const int angle = 90;
public:
    explicit Square(const double side) : side(side) {}

    std::string GetName() override {
        return "Квадрат";
    }

    double getSideA() override {
        return side;
    }

    double getSideB() override {
        return side;
    }

    double getSideC() override {
        return side;
    }

    double getSideD() override {
        return side;
    }

    int getAngleA() override {
        return angle;
    }

    int getAngleB() override {
        return angle;
    }

    int getAngleC() override {
        return angle;
    }

    int getAngleD() override {
        return angle;
    }
};

class Parallelogram : public QuadrupleAbstract {
private:
    const double side1;
    const double side2;

    const int angle1;
    const int angle2;

public:
    Parallelogram(const double side1, const double side2, const int angle1, const int angle2) : side1(side1),
                                                                                                side2(side2),
                                                                                                angle1(angle1),
                                                                                                angle2(angle2) {}

    std::string GetName() override {
        return "Параллелограм";
    }

    double getSideA() override {
       return side1;
    }

    double getSideB() override {
        return side2;
    }

    double getSideC() override {
        return side1;
    }

    double getSideD() override {
        return side2;
    }

    int getAngleA() override {
        return angle1;
    }

    int getAngleB() override {
        return angle2;
    }

    int getAngleC() override {
        return angle1;
    }

    int getAngleD() override {
        return angle2;
    }
};

class Rhombus : public QuadrupleAbstract {
private:
    const double side;

    const int angle1;
    const int angle2;
public:
    Rhombus(const double side, const int angle1, const int angle2) : side(side), angle1(angle1), angle2(angle2) {}

    std::string GetName() override {
        return "Ромб";
    }

    double getSideA() override {
        return side;
    }

    double getSideB() override {
        return side;
    }

    double getSideC() override {
        return side;
    }

    double getSideD() override {
        return side;
    }

    int getAngleA() override {
        return angle1;
    }

    int getAngleB() override {
        return angle2;
    }

    int getAngleC() override {
        return angle1;
    }

    int getAngleD() override {
        return angle2;
    }
};

#endif //CPPM_HOMEWORKS_FIGURES_H
