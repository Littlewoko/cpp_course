#include "complex.h"

#include <iostream>

namespace woko {
    Complex::Complex(): real {0}, imaginary {0} {}
    Complex::Complex(double r, double i): real {r}, imaginary {i} {}
    Complex::Complex(const Complex &other) {
        *this = other;
    }

    const Complex &Complex::operator=(const Complex &other) {
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    Complex operator+(const Complex &a, const Complex &b) {
        return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
    }

    ostream &operator<<(ostream &out, const Complex &c) {
        out << "(" << c.getReal() << "," << c.getImaginary() << ")";
        return out;
    }
}