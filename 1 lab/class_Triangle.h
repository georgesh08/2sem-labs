#ifndef INC_2SEM_LABS_CLASS_TRIANGLE_H
#define INC_2SEM_LABS_CLASS_TRIANGLE_H


class Triangle : public Polygon {
private:
    double vectorLength(Point &vec) {
        return sqrt(pow(vec.GetX(), 2) + pow(vec.GetY(), 2));
    }

public:
    explicit Triangle(Chain &ch) : Polygon(ch) {
        if (chain.size() != 3)
            std::cout << "Not a triangle." << std::endl;
    }

    Triangle &operator=(const Triangle &tr) {
        if (this != &tr)
            this->chain = tr.chain;
        return *this;
    }

    Triangle(const Triangle &triangle_) : Polygon(triangle_) {
        if (triangle_.chain.size() != 3)
            std::cout << "Not a triangle." << std::endl;
    }

    double countSquare() override {
        Point ab(chain[1].GetX() - chain[0].GetX(), chain[1].GetY() - chain[0].GetY()),
                bc(chain[2].GetX() - chain[0].GetX(),
                   chain[2].GetY() - chain[0].GetX()), ac(chain[2].GetX() - chain[1].GetX(),
                                                          chain[2].GetY() - chain[1].GetY());
        if (vectorLength(ab) == vectorLength(bc) && vectorLength(ab) == vectorLength(ac))
            return pow(vectorLength(ab), 2) * sqrt(3) / 4;
        return sqrt(countPerimeter() * (countPerimeter() - vectorLength(ab)) * (countPerimeter() - vectorLength(bc)) *
                    (countPerimeter() - vectorLength(ac)));
    }
};

#endif
