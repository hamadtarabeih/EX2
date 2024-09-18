#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath> // For std::sqrt

class Complex
{
public:
    double real;
    double imag;
    Complex(double r = 0.0, double i = 0.0);

    Complex operator+(const Complex &other) const;
    Complex operator-(const Complex &other) const;
    bool operator==(const Complex &other) const;
    bool operator<(const Complex &other) const;
    
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);

private:
    double magnitude() const;
};

#endif // COMPLEX_HPP