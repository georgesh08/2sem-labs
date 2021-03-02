#ifndef INC_2SEM_LABS_CLASS_POINT_H
#define INC_2SEM_LABS_CLASS_POINT_H

class Point {
private:
    double x, y;
public:
    explicit Point(double valueX = 0, double valueY = 0) {
        x = valueX;
        y = valueY;
    }

    double GetX() const { return x; }

    double GetY() const { return y; }

    void SetX(double a) { x = a; };

    void SetY(double b) { y = b; }

    Point &operator=(Point const &my_point) {
        x = my_point.x;
        y = my_point.y;
        return *this;
    }

    Point(const Point &my_point) : x(my_point.x), y(my_point.y) {}

};

#endif
