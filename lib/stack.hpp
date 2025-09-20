#pragma once

#include "linked_list.hpp"
template <typename T>
class Stack : LinkedList<T> {
  public:
    Stack() : LinkedList<T>() {};
    void push(const T& data);
    T pop();
    bool isEmpty() const;
    std::string toString() const;
};

#include "stack.inl"
