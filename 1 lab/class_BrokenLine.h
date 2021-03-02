#ifndef INC_2SEM_LABS_CLASS_BROKENLINE_H
#define INC_2SEM_LABS_CLASS_BROKENLINE_H

#include <vector>
#include "class_point.h"

class BrokenLine {
private:
    std::vector<Point> points;
public:
    explicit BrokenLine(int n = 0) {
        points.resize(n);
    }

    void Push(double x, double y) {
        Point p(x, y);
        points.emplace_back(p);
    }

    void Push(const Point &p) {
        points.emplace_back(p);
    }

    Point &operator[](int index) {
        return points[index];
    }

    BrokenLine &operator=(const BrokenLine &line) {
        this->points = line.points;
        return *this;
    }

    int size() const {
        return points.size();
    }

    BrokenLine(const BrokenLine &line) : points(line.points) {};
};

#endif
