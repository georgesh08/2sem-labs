#ifndef INC_5_LAB_CIRCULAR_BUFFER_HPP
#define INC_5_LAB_CIRCULAR_BUFFER_HPP

template<typename T>
class Circular_buffer{
public:
    explicit Circular_buffer(int size){
        array = new int[size];
        capacity = size;
        head = array;
        tail = array;
        content_size = 0;
    }

    bool is_full(){
        return capacity == tail-head;
    }

    void increment_tail(){
        ++tail;
        ++content_size;
    }

    int get_content_size(){
        return (tail - head);
    }

    int get_capacity(){
        return this->capacity;
    }

    void increment_head(){
        if(content_size == 0)
            return;
        ++head;
        --content_size;
    }

    void push_back(const T& item){
        if(is_full()) {
            *head = item;
            tail = head;
            increment_head();
        }
        else {
            *tail = item;
            increment_tail();
        }
    }

    void print(){
        for(int i = 0; i < content_size; ++i){
            std::cout << array[i] << " ";
        }
    }

    Circular_buffer &operator[](int i){
    }
private:
    T *head;
    T *tail;
    int capacity;
    int content_size;
    T *array;
};
#endif
