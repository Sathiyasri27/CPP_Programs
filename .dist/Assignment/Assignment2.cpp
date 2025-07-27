#include <iostream>

class Complex {
public:
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }


    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }

private:
    double real;
    double imag;
};

int main() {
    Complex c1, c2;
    std::cout << "Enter real and imaginary parts of first complex number: ";
    std::cin >> c1;
    std::cout << "Enter real and imaginary parts of second complex number: ";
    std::cin >> c2;

    std::cout << "Addition: " << c1 + c2 << std::endl;
    std::cout << "Subtraction: " << c1 - c2 << std::endl;
    std::cout << "Multiplication: " << c1 * c2 << std::endl;

    return 0;
}
