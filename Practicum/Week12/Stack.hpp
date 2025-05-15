#ifndef _STACK_H
#define _STACK_H

#include<iostream>
#include<stdexcept>

template<typename T, size_t N>
class Stack {
public:
    Stack();

    void push(const T& x);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;

    size_t getSize() const;
    size_t getCapacity() const;
    const T* getStack() const;

private:
    T stack[N];
    size_t currentSize;
};


#endif // !_STACK_H

template<typename T, size_t N>
inline Stack<T, N>::Stack() {
    this->currentSize = 0;
}

template<typename T, size_t N>
inline void Stack<T, N>::push(const T& x) {
    if (currentSize == N) {
        throw std::overflow_error("Stack overflow!");
    }

    stack[this->currentSize++] = x;
}

template<typename T, size_t N>
inline void Stack<T, N>::pop() {
    if (this->empty()) {
        throw std::underflow_error("Stack underflow!");
    }

    --this->currentSize;
}

template<typename T, size_t N>
inline T& Stack<T, N>::top() {
    if (this->empty()) {
        throw std::underflow_error("Stack underflow!");
    }

    return this->stack[this->currentSize - 1];
}

template<typename T, size_t N>
inline const T& Stack<T, N>::top() const {
    if (this->empty()) {
        throw std::underflow_error("Stack underflow!");
    }

    return this->stack[this->currentSize - 1];
}

template<typename T, size_t N>
inline bool Stack<T, N>::empty() const {
    return this->currentSize == 0;
}

template<typename T, size_t N>
inline size_t Stack<T, N>::getSize() const {
    return this->currentSize;
}

template<typename T, size_t N>
inline size_t Stack<T, N>::getCapacity() const {
    return N;
}

template<typename T, size_t N>
inline const T* Stack<T, N>::getStack() const {
    return this->stack;
}