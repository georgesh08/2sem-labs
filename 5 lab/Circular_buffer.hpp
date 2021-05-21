#ifndef INC_5_LAB_CIRCULAR_BUFFER_HPP
#define INC_5_LAB_CIRCULAR_BUFFER_HPP

#include <stdexcept>

template<typename T>
class Circular_buffer {
public:
    explicit Circular_buffer(int buf_size) {
        buffer_ = new T[buf_size];
        capacity = buf_size;
        head = tail = buffer_;
        m_end = buffer_ + capacity;
        m_begin = buffer_;
        size = 0;
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


    T *begin() { return m_begin; }

    T *end() {
        if (full())
            return m_end;
        return tail;
    }

    void push_back(T item) {
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
            decrement(tail);
            *tail = *m_end;
            --size;
        }
    }

    void pop_front() {
        if (size == 0)
            throw std::runtime_error("Buffer is empty.");
        else {
            *head = *m_end;
            increment(head);
            --size;
        }
    }

    void push_front(T item) {
        if (full()) {
            if (empty())
                return;
            decrement(head);
            replace(head, item);
            tail = head;
        } else {
            decrement(head);
            replace(head, item);
            ++size;
        }
    }

    void resize(int new_size) {
        int h_pos;
        int t_pos;
        T *tmp = new T[new_size];
        if (new_size > size) {
            if (new_size > capacity)
                capacity = new_size;
            h_pos = head - m_begin;
            t_pos = tail - m_begin;
            for (int i = 0; i < size; ++i) {
                tmp[i] = buffer_[i];
            }
        }
        else{
            h_pos = t_pos = new_size;
            for(int i = 0; i < new_size; ++i){
                tmp[i] = buffer_[i];
            }
            size = new_size;
        }
        delete [] buffer_;
        buffer_ = tmp;
        head = buffer_ + h_pos;
        tail = buffer_ +  t_pos;
        m_begin = buffer_;
        m_end = tmp + new_size;
    }

private:
    T *head;
    T *tail;
    T *m_end;
    T *m_begin;
    int capacity;
    int size;
    T *buffer_;

    void replace(T *pos, T item) {
        *pos = item;
    }

    template<class Pointer>
    void increment(Pointer &ptr) const {
        if (++ptr == m_end)
            ptr = buffer_;
    }

    template<class Pointer>
    void decrement(Pointer &ptr) const {
        if (ptr == buffer_)
            ptr = m_end - 1;
        --ptr;
    }

    template<class Pointer>
    Pointer add(Pointer ptr, int n) const {
        return ptr + ((n + ptr) < m_end ? n : n - capacity);
    }
};

#endif
