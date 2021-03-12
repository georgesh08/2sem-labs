#ifndef INC_2SEM_LABS_CLASS_TRAPEZOID_H
#define INC_2SEM_LABS_CLASS_TRAPEZOID_H

class Trapezoid : public Polygon {
private:
    double vectorLength(Point &vec) {
        return sqrt(pow(vec.GetX(), 2) + pow(vec.GetY(), 2));
    }

    double angle(Point &vec1, Point &vec2) {
        return (vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY()) / vectorLength(vec1) * vectorLength(vec2);
    }

    bool isTrapezoid(Chain &chain_) {
        if (chain_.size() != 4)
            return false;
        Point ab(chain_[1].GetX() - chain_[0].GetX(), chain_[1].GetY() - chain_[0].GetX()),
                dc(chain_[3].GetX() - chain_[2].GetX(), chain_[3].GetY() - chain_[2].GetY());
        Point bc(chain_[2].GetX() - chain_[1].GetX(), chain_[2].GetY() - chain_[2].GetY()),
                ac(chain_[3].GetX() - chain_[0].GetX(), chain_[3].GetY() - chain_[0].GetY());
        if ((angle(ab, dc) == 0 && angle(bc, ac) != 0) || (angle(ab, bc) != 0 && angle(bc, ac) == 0))
            return true;
        return false;
    }

public:
    explicit Trapezoid(Chain &ch) : Polygon(ch) {
        if (!isTrapezoid(ch))
            std::cout << "Not a trapezoid.";
    };

    Trapezoid &operator=(const Trapezoid &trp) {
        if (this != &trp)
            this->chain = trp.chain;
        return *this;
    }

};

#endif
