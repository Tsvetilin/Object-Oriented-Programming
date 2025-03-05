#include <iostream>

namespace Complex
{
    struct ComplexNumber
    {
        int real;
        int imag;
    };

    ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2)
    {
        return {c1.real + c2.real, c1.imag + c2.imag};
    }

    ComplexNumber multiply(const ComplexNumber& c1, const ComplexNumber& c2)
    {
    return {
        c1.real * c2.real - c1.imag * c2.imag, 
        c1.real * c2.imag + c1.imag * c2.real
    };
}

    void printComplexNumber (const ComplexNumber& c)
    {
        std::cout << c.real << " + " << c.imag << "i" << std::endl;
    }
}

int main()
{
    Complex::ComplexNumber c1 = {3, 5};
    Complex::ComplexNumber c2 = {6, 2};
    Complex::ComplexNumber c = Complex::add(c1, c2);
    std::cout << "The sum: ";
    Complex::printComplexNumber(c);

    c = Complex::multiply(c1, c2);
    std::cout << "The multiplication: ";
    Complex::printComplexNumber(c);
}