#pragma once
template <typename T>
class Node {
  public:
    Node(T data);
    T data;
    Node<T>* next;
};
#include "node.inl"
