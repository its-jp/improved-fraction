#pragma once 
#include <stdio.h>
#include "node.hpp"
#include <iostream>
class LinkedList {
  public:
    LinkedList(size_t t);
    LinkedList(const LinkedList& l);

    void addNodeLast(Node* node);
    void addNodeFirst(Node* node);

    Node* removeNodeLast();
    Node* removeNodeFirst();

    std::string toString();
  private:
    size_t data_type;
    Node* head;
};

