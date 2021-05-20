#ifndef INC_5_LAB_CIRCULAR_BUFFER_HPP
#define INC_5_LAB_CIRCULAR_BUFFER_HPP
#include <stdexcept>
#include <cstdlib>

template<typename T>
class Circular_buffer {
public:
    explicit Circular_buffer(int buf_size) {
        buffer_ = new T[buf_size];
        capacity = buf_size;
        head = tail = buffer_;
        buf_end = buffer_ + capacity;
        buf_begin = buffer_;
        size = 0;
    }

    template<class Pointer>
    Pointer add(Pointer ptr, int n) const {
        return ptr + ((n + ptr) < buf_end ? n : n - capacity);
    }

    template<class Pointer>
    void increment(Pointer &ptr) const {
        if (++ptr == buf_end)
            ptr = buffer_;
    }

    template<class Pointer>
    void decrement(Pointer &ptr) const {
        if (ptr == buffer_)
            ptr = buf_end;
        --ptr;
    }

    bool full() const { return capacity == size; }

    bool empty() const { return size == 0; }

    T &operator[](int index) {
        if (index < 0 || index > capacity - 1)
            throw std::runtime_error("Index out of range.");
        return *add(head, index);
    }

    int get_size() const { return size; }

    int get_capacity() const { return capacity; }

    void replace(T *pos, T item) {
        *pos = item;
    }

    T *begin() { return buf_begin; }

    T *end() {
        if (full())
            return buf_end;
        return tail;
    }

    void push_back(const T item) {
        if (full()) {
            if (empty())
                return;
            replace(tail, item);
            increment(tail);
            head = tail;
        } else {
            replace(tail, item);
            increment(tail);
            ++size;
        }
    }

    void pop_back() {
        if (size == 0)
            throw std::runtime_error("Buffer is empty.");
        else {
            if (tail == begin())
                tail = end() - 1;
            else
                --tail;
        }
        --size;
    }

    void push_front() {
        if (head == begin()) {

        }
    }

    void resize(const int new_size) {
        capacity = new_size;
        T *tmp = new T[new_size];
        if (new_size > capacity) {

        }
    }

private:
    T *head;
    T *tail;
    const T *buf_end;
    const T *buf_begin;
    int capacity;
    int size;
    T *buffer_;
};

#endif
