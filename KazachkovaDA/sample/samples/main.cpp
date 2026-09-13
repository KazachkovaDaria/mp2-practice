#include "complex.h"
#include <iostream>

int main()
{
    Complex a(1, 2);
    Complex b(3, 4);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";


    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";

    Complex a2(1, 2);
    std::cout << "a == a2 : " << (a == a2) << "\n";
    std::cout << "a == b  : " << (a == b) << "\n";
    std::cout << "a != b  : " << (a != b) << "\n";
    std::cout << "a != a2 : " << (a != a2) << "\n";

    Complex c;
    c = a;
    std::cout << "c = a -> c = " << c << "\n";
    c = a = b;
    std::cout << "c = a = b -> a = " << a << ", c = " << c << "\n";

    Complex d(1, 1);
    d += b;
    std::cout << "d(1,1) += b -> d = " << d << "\n";

    Complex e(5, 7);
    std::cout << "e = " << e << "\n";
    std::cout << "++e = " << ++e << "\n";
    std::cout << "e = " << e << "\n";
    std::cout << "e++ = " << e++ << "\n";
    std::cout << "e = " << e << "\n";

    Complex f(5, 7);
    std::cout << "f = " << f << "\n";
    std::cout << "--f = " << --f << "\n";
    std::cout << "f = " << f << "\n";
    std::cout << "f-- = " << f-- << "\n";
    std::cout << "f = " << f << "\n";

    Complex hh;
    std::cin >> hh;
    hh++;
    std::cout << hh;
    return 0;
}