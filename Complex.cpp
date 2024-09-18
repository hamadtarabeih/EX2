#include "Complex.hpp"

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex Complex::operator+(const Complex &other) const
{
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex &other) const
{
    return Complex(real - other.real, imag - other.imag);
}

bool Complex::operator==(const Complex &other) const
{
    return real == other.real && imag == other.imag;
}

bool Complex::operator<(const Complex &other) const
{
    return magnitude() < other.magnitude();
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    os << "[" << c.real << ", " << c.imag << "i]";
    return os;
}

double Complex::magnitude() const
{
    return std::sqrt(real * real + imag * imag);
}