#include <string>
#include <iostream>
#include <assert.h>

namespace NS {
    class Complex {
        private:
            double _real;
            double _imaginary;
        public:
            Complex ();
            Complex (double real);
            Complex (double real, double imaginary);
            double real ();
            double imaginary ();
            Complex & operator+= (Complex c);
    };
}

NS::Complex::Complex () :_real { 0. }, _imaginary { 0. } {}
NS::Complex::Complex (double real) :_real { real }, _imaginary { 0. } {}
NS::Complex::Complex (double real, double imaginary) :_real { real }, _imaginary { imaginary } {}

double NS::Complex::real () { return this->_real; }
double NS::Complex::imaginary () { return this->_imaginary; }

NS::Complex & NS::Complex::operator+= (NS::Complex c) {
    this->_real += c.real();
    this->_imaginary += c.imaginary();
    return *this;
}
bool operator== (NS::Complex c, NS::Complex d) {
    return c.real() == d.real() && c.imaginary() == d.imaginary();
}

std::ostream & operator<< (std::ostream & os, NS::Complex c) {
    os << "@" << &c << ":";
    os << c.real() << "," << c.imaginary();
    return os;
}

int
main (int argc, char ** argv) {
    NS::Complex c(3, -2);
    assert(c == c);
    c += NS::Complex(1, 0);
    assert(c.imaginary() == -2);
    assert(c == NS::Complex(4, -2));
    return 0;
}
