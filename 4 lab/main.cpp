#include <iostream>
#include <vector>
#include <algorithm>
#include "STL_Algorithms.hpp"

struct DivisibleBy {
    const int d;
    explicit DivisibleBy(int n) : d(n) {}
    bool operator()(int n) const { return n % d == 0; }
};

template<typename T>
bool sort_comparator(T n1, T n2){
    return n1 > n2;
}

bool palindrome_comparator(int n, int k){
    return (n % 7 == k % 7);
}


int main() {
    std::vector<int> arr3 = {1, 3, 5, 5, 11, 9, 7, 13, 13, 15, 13};
    std::cout << stl_alg::all_of(arr3.begin(), arr3.end(), DivisibleBy(2)) << "\n";
    std::cout << stl_alg::none_of(arr3.begin(), arr3.end(), DivisibleBy(100)) << "\n";
    std::cout << stl_alg::any_of(arr3.begin(), arr3.end(), DivisibleBy(9)) << "\n";
    std::cout << stl_alg::one_of(arr3.begin(), arr3.end(), DivisibleBy(5)) << "\n";
    std::cout << *stl_alg::find_not(arr3.begin(), arr3.end(), 11) << "\n";
    std::cout << *stl_alg::find_backward(arr3.begin(), arr3.end(), 5) << "\n";
    std::vector<int> arr4 = {2, 4, 6, 8, 10, 5, 9, 1};
    std::cout << stl_alg::is_partitioned(arr4.begin(), arr4.end(), DivisibleBy(2)) << "\n";
    std::vector<double> arr2 = {1, 2, 4, 0, 5, 7};
    std::cout << stl_alg::is_sorted(arr2.begin(), arr2.end(), sort_comparator<std::iterator_traits<typeof(arr2.begin())>::value_type>) << "\n";
    std::vector<int> arr1 = {7, 14, 2, 21, 28};
    std::cout << stl_alg::is_palindrome(arr1.begin(), arr1.end(), palindrome_comparator);
    return 0;
}
