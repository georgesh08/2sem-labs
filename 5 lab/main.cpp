#include <iostream>
#include <algorithm>
#include <vector>
#include "Circular_buffer.hpp"

int main() {
    Circular_buffer<int> cb(3);
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    for (int i = 0; i < 3; ++i) {
        std::cout << cb[i] << " ";
    }
    cb.push_back(4);
    cb.push_back(5);
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << cb[i] << " ";
    }
/*    std::cout << "Buffer:\n";
    std::cout << cb.get_capacity() << " " << sizeof(Circular_buffer<int>) + cb.get_content_size()*sizeof(int) << " " << cb.get_content_size() << "\n";
    cb.pop_back();
    std::cout << cb.get_capacity() << " " << sizeof(Circular_buffer<int>) + cb.get_content_size()*sizeof(int) << " " << cb.get_content_size() << "\n";
    std::vector<int> tmp(3);
    for (int i = 0; i < tmp.size(); ++i) {
        tmp[i] = i + 1;
    }
    std::cout << "Vector:\n";
    std::cout << tmp.capacity() << " " << tmp.size() * sizeof(int) + sizeof(std::vector<int>) << " " << tmp.size()
              << "\n";
    tmp.pop_back();
    std::cout << tmp.capacity() << " " << tmp.size() * sizeof(int) + sizeof(std::vector<int>) << " " << tmp.size()
              << "\n";*/
    return 0;
}