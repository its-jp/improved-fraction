#pragma once
#include <cstddef>
class Node {
  public:
    Node(size_t t);
    void* data;
    Node* next;
};
