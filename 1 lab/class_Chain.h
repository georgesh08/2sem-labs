#ifndef INC_2SEM_LABS_CLASS_CHAIN_H
#define INC_2SEM_LABS_CLASS_CHAIN_H

#include <vector>
#include "class_point.h"

class Chain {
private:
    std::vector<Point> points;
public:
    explicit Chain(int n = 0) {
        if (n == 0)
            points.clear();
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
        return points[index % points.size()];
    }

    Chain &operator=(const Chain &chain) {
        this->points = chain.points;
        return *this;
    }

    int size() const {
        return points.size();
    }

    Chain(const Chain &chain) : points(chain.points) {};
};

#endif

