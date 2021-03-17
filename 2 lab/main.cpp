#include <iostream>
#include "polynomial.h"

int main() {
    Polynomial p1(4);
    Polynomial p2(3);
    std::cout << "Enter p1 and p2 coeffs: " << std::endl;
    std::cin >> p1 >> p2;
    std::cout << "We have 2 polynomials - p1 and p2, they are: " << std::endl << p1 << std::endl << p2 <<std::endl;
    std::cout << "Their sum is: " << p1+p2 << std::endl;
    std::cout << "Their product is: " << p1*p2 << std::endl;
    std::cout << "Their difference is: " << p1-p2 << std::endl;
    std::cout << "Here is -p1: " << -p1 << std::endl;
    Polynomial p3(p1);
    Polynomial p4 = p2;
    std::cout << "Now we have two more polynomials p3 = p1 and p4 = p2" << std::endl;
    std::cout << "Enter a number: " << std::endl;
    double num;
    std::cin >> num;
    std::cout << "Let's find p1/num: " << p1/num << std::endl;
    p3 *= p4;
    std::cout << "Now p3 = p3*p4: " << p3;
    return 0;
}
