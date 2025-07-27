#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class Shape {
public:
    Shape(const std::string& name) : name(name) {}
    virtual double calculateArea() const = 0; 
    virtual ~Shape() {} 

protected:
    std::string name;
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double breadth) : Shape("Rectangle"), length(length), breadth(breadth) {}
    double calculateArea() const override {
        return length * breadth;
    }

private:
    double length;
    double breadth;
};

class Circle : public Shape {
public:
    Circle(double radius) : Shape("Circle"), radius(radius) {}
    double calculateArea() const override {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

class Triangle : public Shape {
public:
    Triangle(double base, double height) : Shape("Triangle"), base(base), height(height) {}
    double calculateArea() const override {
        return 0.5 * base * height;
    }

private:
    double base;
    double height;
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(std::make_unique<Circle>(4.0));
    shapes.push_back(std::make_unique<Triangle>(6.0, 2.5));

    std::cout << "Shape Areas:" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << "Area of " << typeid(*shape).name() << ": " << shape->calculateArea() << std::endl;
    }

    return 0;
}
