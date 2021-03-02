#ifndef INC_2SEM_LABS_CLASS_REGULARPOLYGON_H
#define INC_2SEM_LABS_CLASS_REGULARPOLYGON_H

#include <cmath>

class RegularPolygon : public Polygon {
private:
    double vectorLength(Point& vec) {
        return sqrt(pow(vec.GetX(), 2) + pow(vec.GetY(), 2));
    }
public:
    bool isRegularPolygon(Chain chain_) {
        Point ab(chain_[1].GetX() - chain_[0].GetX(), chain_[1].GetY() - chain_[0].GetY()),
                bc(chain_[chain_.size() - 1].GetX() - chain_[0].GetX(),
                   chain_[chain_.size() - 1].GetY() - chain_[0].GetX());
        double angle = acos((ab.GetX()*bc.GetX() + ab.GetY()*bc.GetY()) / vectorLength(ab) * vectorLength(bc));
        for(int i = 1; i < chain_.size(); i++){
            double temp;
            ab.SetX(chain_[i-1].GetX() - chain_[i].GetX());
            ab.SetY(chain_[i-1].GetY() - chain_[i].GetY());
            bc.SetX(chain_[i+1].GetX() - chain_[i].GetX());
            bc.SetY(chain_[i+1].GetY() - chain_[i].GetY());
            temp = acos((ab.GetX()*bc.GetX() + ab.GetY()*bc.GetY()) / vectorLength(ab) * vectorLength(bc));
            if(temp != angle)
                return false;
        }
        return true;
    }

    explicit RegularPolygon(const Chain &ch) : Polygon(ch) {
        if (!isRegularPolygon(ch))
            std::cout << "Not a regular polygon.";
    }

    RegularPolygon &operator=(const RegularPolygon &rp){
        if(this != &rp)
            this->chain = rp.chain;
        return *this;
    }

    RegularPolygon(const RegularPolygon &rp) : Polygon(rp) {}
};

#endif
