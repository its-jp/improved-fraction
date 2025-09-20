#pragma once
#include "linked_list.hpp"
template <typename T>
class Queue : private LinkedList<T> {
  public:
    Queue() : LinkedList<T>() {};
    void enqueue(const T& data);
    T dequeue();
    bool isEmpty() const;
    std::string toString() const;
};

#include "queue.inl"
