#include <iostream>
#include "class_point.h"
#include "class_Chain.h"
#include "class_BrokenLine.h"
#include "class_Polygon.h"
#include "class_Trapezoid.h"
#include "class_Triangle.h"
#include "class_RegularPolygon.h"


int main() {
    std::cout << "//POINT CLASS:" << std::endl;
    Point a;
    std::cout << "Point A.x = " << a.GetX() << ", A.y = " << a.GetY() << std::endl;
    a.SetX(1.1);
    a.SetY(2.2);
    std::cout << "Now A.x = " << a.GetX() << ", A.y = " << a.GetY() << std::endl;
    Point b = a;
    std::cout << "Point B equals A: B.x = " << b.GetX() << ", B.y = " << b.GetY() << std::endl;
    std::cout << "//BROKEN LINE CLASS:" << std::endl;
    BrokenLine br;
    std::cout << "Broken line br just created. It's size is " << br.size() << std::endl;
    br.Push(a);
    br.Push(3.3, 4.4);
    std::cout << "Now broken line size is " << br.size() << ". It's second point is (" << br[1].GetX() << ", "
              << br[1].GetY() << ")" << std::endl;
    BrokenLine br1(br);
    std::cout << "We just got one more broken line - br1, which equals br" << std::endl;
    std::cout << "//CHAIN CLASS:" << std::endl;
    Chain chain1(3);
    Point c(0, 0);
    chain1[0] = a;
    chain1[1] = c;
    chain1[2] = br[1];
    Chain chain2 = chain1;
    std::cout << "We got chain2, it's points are: ";
    for (int i = 0; i < chain2.size(); i++)
        std::cout << " (" << chain2[i].GetX() << ", " << chain2[i].GetY() << ")";
    Chain chain3(chain1);
    std::cout << "\nWe have 3 chains: chain1, chain2, chain3, and they are equal" << std::endl;
    std::cout << "//POLYGON CLASS:" << std::endl;
    Chain chainPolygon1(4);
    chainPolygon1[0].SetX(1);
    chainPolygon1[0].SetY(1);
    chainPolygon1[1].SetX(4);
    chainPolygon1[1].SetY(2);
    chainPolygon1[2].SetX(3);
    chainPolygon1[2].SetY(4);
    chainPolygon1[3].SetX(2);
    chainPolygon1[3].SetY(5);
    Polygon pol1(chainPolygon1);
    std::cout << "Now we have polygon. It's square is " << pol1.countSquare() << ", and it's perimeter is "
              << pol1.countPerimeter() << std::endl;
    Polygon pol2(pol1);
    std::cout << "//TRIANGLE CLASS:" << std::endl;
    Chain chainTriangle(3);
    chainTriangle[0] = c;
    chainTriangle[1].SetX(3);
    chainTriangle[1].SetY(1);
    chainTriangle[2].SetX(2);
    chainTriangle[2].SetY(4);
    Triangle tr1(chainTriangle);
    std::cout << "We created triangle tr1. It's square is " << tr1.countSquare() << ", it's perimeter is "
              << tr1.countPerimeter() << std::endl;
    std::cout << "//TRAPEZOID CLASS:" << std::endl;
    Chain trapezoidChain;
    Point ab(1, 1), bc(4, 1), cd(3, 3), ac(1, 3);
    trapezoidChain.Push(ab);
    trapezoidChain.Push(bc);
    trapezoidChain.Push(cd);
    trapezoidChain.Push(ac);
    Trapezoid trp(trapezoidChain);
    std::cout << "We created trapezoid. It's square is " << trp.countSquare() << ", it's perimeter is "
              << trp.countPerimeter() << std::endl;
    std::cout << "//CLASS REGULAR POLYGON:" << std::endl;
    ab.SetX(0);
    ab.SetY(0);
    bc.SetX(2);
    bc.SetY(0);
    cd.SetX(2);
    cd.SetY(2);
    ac.SetX(0);
    ac.SetY(2);
    Chain chainRegularPol;
    chainRegularPol.Push(ab);
    chainRegularPol.Push(bc);
    chainRegularPol.Push(cd);
    chainRegularPol.Push(ac);
    RegularPolygon rp(chainRegularPol);
    std::cout << "Now we have regular polygon. It's square is " << rp.countSquare() << ", perimeter is "
              << rp.countPerimeter();
    return 0;
}
