#ifndef INC_2SEM_LABS_CLASS_POLYGON_H
#define INC_2SEM_LABS_CLASS_POLYGON_H

#include <vector>
#include "class_point.h"
#include "class_Chain.h"
#include <math.h>

class Polygon {
protected:
    Chain chain;

    bool IsPolygon(Chain chain_) {
        int product;
        Point ab(chain_[0].GetX() - chain_[chain_.size() - 1].GetX(),
                 chain_[0].GetY() - chain_[chain_.size() - 1].GetY()), bc(chain_[1].GetX() - chain_[0].GetX(),
                                                                          chain_[1].GetY() - chain_[0].GetY());
        product = ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX();
        if (product == 0)
            return false;
        int sign = product/abs(product);
        for (int i = 1; i < chain_.size(); i++) {
            ab.SetX(chain_[i].GetX() - chain_[i - 1].GetX());
            ab.SetY(chain_[i].GetY() - chain_[i - 1].GetY());
            bc.SetX(chain_[i + 1].GetX() - chain_[i].GetX());
            bc.SetY(chain_[i + 1].GetY() - chain_[i].GetY());
            product = ab.GetX() * bc.GetY() - ab.GetY() * bc.GetX();
            if (product == 0)
                return false;
            if(sign != product/abs(product))
                return false;
        }
        return true;
    }
public:
    Polygon(const Chain &ch) {
        if (IsPolygon(ch))
            chain = ch;
    }

    virtual double countSquare() {
        if (chain.size() == 0)
            return -1;
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < chain.size() - 1; i++) {
            sum1 += chain[i].GetX() * chain[i + 1].GetY();
        }
        for (int i = 0; i < chain.size() - 1; i++) {
            sum2 += chain[i + 1].GetX() * chain[i].GetY();
        }
        return abs(sum1 - sum2 - chain[0].GetX() * chain[chain.size() - 1].GetY() +
                    chain[chain.size() - 1].GetX() * chain[0].GetY())*0.5;
    }

    double countPerimeter() {
        double perim = 0;
        for (int i = 0; i < chain.size(); i++) {
            perim += sqrt(
                    pow(chain[i].GetX() - chain[i + 1].GetX(), 2) + pow(chain[i].GetY() - chain[i + 1].GetY(), 2));
        }
        return perim;
    }

    Polygon &operator=(const Polygon &polygon) {
        if (&polygon != this)
            this->chain = polygon.chain;
        return *this;
    }

    Polygon(const Polygon &polygon) : chain(polygon.chain) {};

};

#endif
