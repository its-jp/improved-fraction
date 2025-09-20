#pragma once 
#include <stdio.h>
#include "node.hpp"
#include <iostream>

template <typename T>
class LinkedList {
  public:
    LinkedList();
    LinkedList(const LinkedList<T>& l);

    void addNodeLast(Node<T>* node);
    void addNodeFirst(Node<T>* node);

    Node<T>* removeNodeLast();
    Node<T>* removeNodeFirst();

    std::string toString();
  private:    
    Node<T>* head;
};

#include "linked_list.inl"
