#include <iostream>
#include <algorithm>
#include "Circular_buffer.hpp"

int main(){
    Circular_buffer<int> cb(3);
    cb.push_back(12);
    cb.push_back(2);
    cb.push_back(9);
    cb.pop_back();
    cb.print();
    return 0;
}