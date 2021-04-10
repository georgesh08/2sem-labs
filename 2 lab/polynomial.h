#ifndef INC_2_LAB_POLYNOMIAL_H
#define INC_2_LAB_POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <algorithm>


class Polynomial {
private:
    std::vector<double> coeff;
public:

    explicit Polynomial(int n = 0) {
        coeff.resize(n);
    }

    Polynomial(const Polynomial &p1) : coeff(p1.coeff) {};

    Polynomial &operator=(const Polynomial &pol1) {
        this->coeff = pol1.coeff;
        return *this;
    }

    double &operator[](const int index) {
        return coeff[index];
    }

    bool operator==(const Polynomial &pol1) {
        return coeff == pol1.coeff;
    }

    bool operator!=(const Polynomial &pol1) {
        return !(*this == pol1);
    }

    Polynomial operator/(double num) const {
        Polynomial tmp(*this);
        tmp/=num;
        return tmp;
    }

    Polynomial &operator/=(double num) {
        for (int i = 0; i < coeff.size(); ++i)
            coeff[i] /= num;
        return *this;
    }

    Polynomial operator+(const Polynomial &p1) const {
        Polynomial tmp(*this);
        tmp += p1;
        return tmp;
    }

    Polynomial operator-() const {
        Polynomial tmp(coeff.size());
        for (int i = 0; i < coeff.size(); ++i) {
            tmp.coeff[i] = -coeff[i];
        }
        return tmp;
    }

    Polynomial operator-(const Polynomial &p1) const {
        Polynomial tmp(*this);
        tmp -= p1;
        return tmp;
    }

    Polynomial &operator+=(const Polynomial &p1) {
        coeff.resize(p1.coeff.size() > coeff.size() ? p1.coeff.size() : coeff.size());
        for (int i = 0; i < coeff.size(); ++i) {
            coeff[i] += p1.coeff[i];
        }
        return *this;
    }

    Polynomial &operator-=(const Polynomial &p1) {
        coeff.resize(p1.coeff.size() > coeff.size() ? p1.coeff.size() : coeff.size());
        for (int i = 0; i < coeff.size(); ++i) {
            coeff[i] -= p1.coeff[i];
        }
        return *this;
    }

    Polynomial operator*(const Polynomial &p1) const {
        Polynomial tmp(*this);
        tmp *= p1;
        return tmp;
    }

    Polynomial &operator*=(const Polynomial &p1) {
        Polynomial tmp(coeff.size() + p1.coeff.size() - 1);
        for (int i = coeff.size()-1; i >= 0; --i) {
            for (int j = p1.coeff.size()-1; j >= 0; --j)
                tmp[i + j] += coeff[i] * p1.coeff[j];
        }
        this->coeff = tmp.coeff;
        return *this;
    }

    Polynomial findDerivative(){
        Polynomial tmp = *this;
        std::reverse(tmp.coeff.begin(), tmp.coeff.end());
        tmp.coeff.pop_back();
        std::reverse(tmp.coeff.begin(), tmp.coeff.end());
        for(int i = 0; i < tmp.coeff.size(); i++){
            tmp.coeff[i] *= i+1;
        }
        return tmp;
    }


    friend std::ostream &operator<<(std::ostream &out, Polynomial p1);

    friend std::istream &operator>>(std::istream &in, Polynomial &p2);

};

std::ostream &operator<<(std::ostream &out, Polynomial p1) {
    for (int i = p1.coeff.size() - 1; i > 0; --i) {
        if (p1.coeff[i] != 0)
            out << p1.coeff[i] << "*x^" << i << (p1.coeff[i - 1] >= 0 ? " + " : "");
    }
    out << p1.coeff[0];
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &p2) {
    int n;
    in >> n;
    p2.coeff.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        in >> p2.coeff[i];
    }
    return in;
}

#endif
