#ifndef INC_5_LAB_CIRCULAR_BUFFER_HPP
#define INC_5_LAB_CIRCULAR_BUFFER_HPP
#include <stdexcept>

template<typename T>
class Circular_buffer {
public:
    explicit Circular_buffer(int size) {
        array = new int[size];
        capacity = size;
        head = tail = array;
        tail = array;
        content_size = 0;
    }

    bool is_full() {
        return capacity == content_size;
    }

    void increment_tail() {
        ++tail;
        if (capacity != content_size)
            ++content_size;
    }

    T &operator[](const int index){
        return *(array + index);
    }

    int get_content_size() const {
        return content_size;
    }

    int get_capacity() const {
        return capacity;
    }

    bool is_empty() const {
        return content_size == 0;
    }

    void increment_head() {
        if (content_size == 0)
            return;
        ++head;
    }

    T* begin(){
        return array;
    }

    T* end(){
        if(content_size < capacity)
            return tail;
        return array+capacity;
    }

    void push_back(const T &item) {
        if (is_full()) {
            if(head == end()-1){
                tail = head;
                *tail = item;
                head = begin();
            }
            else {
                tail = head;
                *tail = item;
                increment_head();
            }
        } else {
            *tail = item;
            increment_tail();
        }
    }

    void pop_back(){
        if(content_size == 0)
            throw std::runtime_error("Buffer is empty");
        else{
            if(tail == begin())
                tail = end()-1;
            else if(tail == end()){
                tail -= 2;
            }
            else
                --tail;
        }
        --content_size;
    }

    void print() {
        for (int i = 0; i < content_size; ++i) {
            std::cout << array[i] << " ";
        }
    }

private:
    T* head;
    T* tail;
    int capacity;
    int content_size;
    T* array;
};

#endif
