#ifndef INC_4_LAB_STL_ALGORITHMS_HPP
#define INC_4_LAB_STL_ALGORITHMS_HPP

namespace stl_alg {
    template<class InputIterator, class Predicate>
    bool all_of(InputIterator first, InputIterator last, Predicate pred) {
        while (first != last) {
            if (!pred(*first)) return false;
            ++first;
        }
        return true;
    }

    template<class InputIterator, class UnaryPredicate>
    bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
        while (first != last) {
            if (pred(*first))
                return false;
            ++first;
        }
        return true;
    }

    template<class InputIterator, class UnaryPredicate>
    bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
        while (first != last) {
            if (pred(*first))
                return true;
            ++first;
        }
        return false;
    }

    template<class InputIterator, class UnaryPredicate>
    bool one_of(InputIterator first, InputIterator last, UnaryPredicate pred) {
        int count = 0;
        while (first != last) {
            if (pred(*first))
                count++;
            ++first;
        }
        return count == 1;
    }

    template<class Iterator, class Compare>
    bool is_sorted(Iterator first, Iterator last, Compare compare_) {
        if (first == last)
            return true;
        Iterator next = first;
        while (++next != last) {
            if (compare_(*first, *next))
                return false;
            ++first;
        }
        return true;
    }

    template<class Iterator, typename T>
    Iterator find_not(Iterator first, Iterator last, const T &predicate_) {
        while (first != last) {
            if (*first != predicate_)
                return first;
            ++first;
        }
        return last;
    }

    template<class Iterator, typename T>
    Iterator find_backward(Iterator first, Iterator last, const T &predicate_) {
        Iterator tmp = last;
        while (tmp != first) {
            --tmp;
            if (*tmp == predicate_)
                return tmp;
        }
        return last;
    }

    template<class InputIterator, class UnaryPredicate>
    bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate predicate_) {
        while (first != last && predicate_(*first)) {
            ++first;
        }
        while (first != last) {
            if (predicate_(*first)) return false;
            ++first;
        }
        return true;
    }

    template<class InputIterator, class Predicate>
    bool is_palindrome(InputIterator first, InputIterator last, Predicate predicate_) {
        while(first != last) {
            --last;
            if(first == last)
                return true;
            if (!predicate_(*first, *last))
                return false;
            ++first;
        }
        return true;
    }
}

#endif
