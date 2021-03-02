#ifndef INC_2SEM_LABS_CLASS_TRIANGLE_H
#define INC_2SEM_LABS_CLASS_TRIANGLE_H
class Triangle : public Polygon{
public:
    explicit Triangle(const Chain& ch) : Polygon(ch) {
        if(chain.size() != 3)
            std::cout << "Not a triangle." << std::endl;
    }

    Triangle &operator=(const Triangle &tr){
        if(this != &tr)
            this->chain = tr.chain;
        return *this;
    }

    Triangle(const Triangle &triangle_) : Polygon(triangle_) {
        if(triangle_.chain.size() != 3)
            std::cout << "Not a triangle." << std::endl;
    }
};
#endif
